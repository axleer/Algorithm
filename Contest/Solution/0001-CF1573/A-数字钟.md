#### 一、题目地址

原链接：https://codeforces.com/contest/1573/problem/A

#### 二、题目分析

方法：寻找规律

1）数字钟中的数字减一是指最后一位减一，准确说是数值上的减。

2）对于低位优先减完，对于高位换到低位然后减完，一次迭代即可完成。

#### 三、题目解答

```cpp
#include <iostream>

using namespace std;

void solve() {
    int    len;
    string clock;
    cin >> len >> clock;

    int result = clock[clock.size() - 1] - '0'; // 最后一个数字特殊处理.
    
    for (int i = 0; i < clock.size() - 1; i++) {
        if (clock[i] != '0') { // 判断是否需要交换.
            result += clock[i] - '0' + 1;
        }
    }
    
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int    times;
    cin >> times;

    for (int i = 0; i < times; i++) solve();
}
```
