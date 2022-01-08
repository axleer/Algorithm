#include "tree.h"

BTNode* BTNode::build(istream &in) {
    int val = NULL_VAL;
    if (!(in >> val)) {
        throw runtime_error("build fail due to bad sequence");
    }
    if (val == NULL_VAL) return nullptr;
    auto root   = new BTNode;
    root->val   = val;
    root->left  = build(in);
    root->right = build(in);
    return root;
}

void BTNode::display(BTNode *root) {
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
            BTNode::display_space(space >> 1);
            last = false;
        }

        auto front = sequence.front();

        // print the value.
        if (front == nullptr) {
            cout << "*";
            sequence.push(nullptr);
            sequence.push(nullptr);
        } else {
            cout << front->val;
            sequence.push(front->left);
            sequence.push(front->right);
        }

        sequence.pop();

        if (++count == (1 << depth) - 1) {
            BTNode::display_space(space >> 1);
            cout << endl;
            depth++;
            space >>= 1;
            last = true;
        } else {
            BTNode::display_space(space);
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
