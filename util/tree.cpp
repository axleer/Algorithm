#include "tree.h"

BTNode* BTNode::build(istream &in, BTNode* parent) {
    int val = NULL_VAL;

    // 读入数字错误: 抛出异常.
    if (!(in >> val)) {
        throw runtime_error("build fail due to bad sequence");
    }

    if (val == NULL_VAL) return nullptr;

    auto root   = new BTNode;

    // 将值和双亲正确赋值.
    root->val    = val;
    root->parent = parent;

    // 构建左子树和右子树.
    root->left  = build(in, root);
    root->right = build(in, root);

    return root;
}

void BTNode::display(BTNode *root, ostream &out) {
    if (root == nullptr) return;

    int  space = BTNode::space(root);
    int  count = 0;
    int  depth = 1;
    bool last  = true;

    queue<BTNode*> sequence;

    sequence.push(root);

    while (space != 0) {
        // display line start space.
        if (last) {
            BTNode::display_space(space >> 1, out);
            last = false;
        }

        auto front = sequence.front();

        // print the value.
        if (front == nullptr) {
            out << "*";
            sequence.push(nullptr);
            sequence.push(nullptr);
        } else {
            out << front->val;
            sequence.push(front->left);
            sequence.push(front->right);
        }

        sequence.pop();

        if (++count == (1 << depth) - 1) {
            BTNode::display_space(space >> 1, out);
            cout << endl;
            depth++;
            space >>= 1;
            last = true;
        } else {
            BTNode::display_space(space, out);
        }
    }
}

int BTNode::level(BTNode *root) {
    if (root == nullptr) {
        return 0;
    }
    return max(level(root->left), level(root->right)) + 1;
}

int BTNode::space(BTNode *root) {
    int init = 0, level = BTNode::level(root);

    for (int i = 0; i < level; i++) {
        init = (init << 1) | 0x1;
    }

    return init;
}

void BTNode::print(BTNode *root, ostream &out, bool verbose) {
    if (!root) {
        out << "*";
    } else if (verbose) {
        out << '(';
        print(root->left, out);
        out << ',' << root->val << ',';
        print(root->right, out);
        out << ')';
    } else {
        out << '(';
        out << (root->left ? '+' : '*');
        out << ',' << root->val << ',';
        out << (root->right ? '+' : '*');
        out << ')';
    }
}