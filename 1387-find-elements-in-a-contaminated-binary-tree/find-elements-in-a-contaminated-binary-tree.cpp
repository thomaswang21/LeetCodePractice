#include <unordered_set>

// Make sure TreeNode is defined before including this code block.

class FindElements {
    // 帮助 find 函数快速判断
    std::unordered_set<int> values;

public:
    FindElements(TreeNode* root) {
        // 还原二叉树中的值
        traverse(root, 0);
    }

    // 二叉树遍历函数
    void traverse(TreeNode* root, int val) {
        if (root == nullptr) {
            return;
        }
        root->val = val;
        values.insert(val);

        traverse(root->left, 2 * val + 1);
        traverse(root->right, 2 * val + 2);
    }

    bool find(int target) {
        return values.count(target) > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */