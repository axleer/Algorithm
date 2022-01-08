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
     * 输出一个简单的树, 值的范围应该在[0, 10)内以保证显示效果.
     */
    static void display(BTNode* root);

    /*
     * 使用完整的前序遍历序列构造一个树, 空节点用'-1'表示.
     */
    static BTNode* build(istream &in);

private:
    static constexpr int NULL_VAL = -1;

    /*
     * This get the level in the tree.
     */
    static int level(BTNode* root);

    /*
     * This get the space between elements.
     */
    static int space(BTNode* root);

    /*
     * This display the space between element.
     */
    static void display_space(int len) {
        for (int i = 0; i < len; i++) cout << ' ';
    }
};