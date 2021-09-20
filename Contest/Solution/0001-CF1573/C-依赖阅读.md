#### 一、题目地址

原链接：https://codeforces.com/contest/1573/problem/C

#### 二、题目分析

方法：深度优先搜索、动态规划

1）最自然的想法就是通过无限迭代最终一次次的读完整本书，但显然会超时。

2）于是就想起了动态规划，我们通过深度优先一直读到依赖的最深处，同时动态保存求过的值。

3）然后就出现了新问题：当书之间依赖交叉时，整本书读不完，也就陷入了无限递归，最终因栈满而崩溃。

4）所以这么干之前就先要检查是否能够读完整本书，于是我们不得不在动态规划中引入一个中间态。

5）动态规划的状态：还未计算、正在计算（中间态）、已经计算。

6）递归时两个中间态同时存在标志着无限递归，我们立即输出结果并返回。

#### 三、题目解答

```cpp
#include <iostream>
#include <vector>

using namespace std;

#define LIMIT    (200001)
#define START    (0)
#define PROGRESS (1)
#define DONE     (2)

vector<int> book[LIMIT];

int status[LIMIT];
int rTimes[LIMIT];

// 函数名deepSearch更号,变量deadLock可能不准确.
void deepFind(int chapter, bool &deadLock) {
    status[chapter] = PROGRESS; // 计算正在进行

    for (int i : book[chapter]) {
        switch (status[i]) {
            case PROGRESS: // 需要调用正在进行的计算会导致无限递归.
                deadLock = true;
                return;
            case START:
                deepFind(i, deadLock); // 向深处搜索.
        }
    }
    
    status[chapter] = DONE;
}

void readChapter(int chapter) {
    status[chapter] = DONE;

    if (book[chapter].empty()) {
        rTimes[chapter] = 1;
        return;
    }

    for (int require : book[chapter]) {
        // 保证了rTimes[require]已经计算后面可以当已知值使用.
        if (status[require] == START) readChapter(require);

        // 第一次迭代时,rTimes[chapter]的值是0.那么其会被第一个依赖更新
        // 后续迭代本质上是和之前的最来依赖次数进行比较.
        if (require > chapter) {
            rTimes[chapter] = max(rTimes[chapter], rTimes[require] + 1);
        } else {
            rTimes[chapter] = max(rTimes[chapter], rTimes[require]);
        }
    }
}

void solve() {
    int    chapters;
    cin >> chapters;

    // 变量清理和输入.
    for (int i = 1; i <= chapters; i++) {
        book[i].clear();
        status[i] = START;
        rTimes[i] = 0;

        int    amount, require;
        cin >> amount;

        for (int j = 0; j < amount; j++) {
            cin >> require;
            book[i].push_back(require);
        }
    }

    // 检查是否有无限递归现象.
    bool deadLock = false;
    for (int i = 1; i <= chapters; i++) {
        if (status[i] == START) {
            deepFind(i, deadLock);
            if (deadLock) {
                cout << -1 << endl;
                return;
            }
        }
    }

    // 检查完毕后将状态置为START.
    for (int i = 1; i <= chapters; i++) status[i] = START;

    // 读完所有章节. 
    for (int i = 1; i <= chapters; i++) {
        if (status[i] == START) readChapter(i); // 没读完就开始读.
    }

    // 遍历结果表打印需要最大次数.
    int result = 0;
    for (int i = 1; i <= chapters; i++) result = max(result, rTimes[i]);
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int    cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) solve();
}
```
