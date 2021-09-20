#### 一、题目地址

原链接：https://codeforces.com/contest/1573/problem/B

#### 二、题目分析

方法：动态规划

1）由于只要求两个数组中第一个数字的相对大小。

2）理论上两个数组中任何一个数字都可以通过一定次序的交换移到开头，只是次数不同而已。

3）所以可以暴力枚举所有情况，选出最小值变换次数，可惜他的时间复杂度为O(n²)。

4）这时我们用空间换时间，用一个表来存储一些计算结果，怎么存就是关键所在。

5）既然我们将一个奇数换到开头满足了相对顺序，那么比它小的任何奇数都在此时此刻满足要求，称之为等价移动。

6）于是对于每一个奇数，等价移动需要的最小次数为较小的邻近奇数的等价移动与它自身移动次数的最小值。

7）最终我们通过时间复杂度为O(n)的迭代，填满了一个计算结果表，来减少运行时间。

#### 三、题目解答

```cpp
#include <iostream>

using namespace std;

void solve() {
    int    len;
    cin >> len;

    int odds[len], evens[len], oldTable[len], betterTable[len];
    for (int i = 0; i < len; i++) {
        cin >> odds[i];
        oldTable[(odds[i] - 1) / 2] = i; // 计算每个元素自身移动到开头的变化次数.
    }
    for (int i = 0; i < len; i++) {
        cin >> evens[i];
    }

    betterTable[0] = oldTable[0];
    for (int i = 1; i < len; i++) {
        betterTable[i] = min(betterTable[i - 1], oldTable[i]); // 从上一个表计算等价移动次数.
    }

    int result = len * 2;
    for (int i = 0; i < len; i++) {
        result = min(result, betterTable[evens[i] / 2 - 1] + i); // 查表找最小值.
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
