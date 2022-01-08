#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * 这是二叉树三叉链表表示形式的节点.
 */
class BTNode {
public:
    int     val    = 0;
    BTNode* left   = nullptr;
    BTNode* right  = nullptr;
    BTNode* parent = nullptr;

    /*
     * 用深度优先的方法输出树, 值的范围应该在[0, 10)内以保证显示效果.
     */
    static void display(BTNode* root, ostream &out = cout);

    /*
     * 用类广义表的方法输出树, 节点数量应该较少以保证显示效果.
     * 当verbose模式关闭后, 仅会输出当前接节点的相关信息.
     */
    static void print(BTNode* root, ostream &out = cout, bool verbose = false);

    /*
     * 使用完整的前序遍历序列构造一个树, 空节点用'-1'表示.
     */
    static BTNode* build(istream &in, BTNode* parent = nullptr);

private:
    static constexpr int NULL_VAL = -1;

    /*
     * 获取树的深度.
     */
    static int level(BTNode* root);

    /*
     * 获取元素间空格数.
     */
    static int space(BTNode* root);

    /*
     * 打印空格.
     */
    static void display_space(int len, ostream &out) {
        for (int i = 0; i < len; i++) cout << ' ';
    }
};
