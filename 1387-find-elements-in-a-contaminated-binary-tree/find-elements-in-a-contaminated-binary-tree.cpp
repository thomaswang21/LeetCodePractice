

class FindElements {
private:
    unordered_set<int> values; // 存储恢复后的所有节点值

    // 递归恢复函数
    void recover(TreeNode* node, int val) {
        if (node == nullptr) return;
        node->val = val;
        values.insert(val);
        if (node->left != nullptr) recover(node->left, 2 * val + 1);
        if (node->right != nullptr) recover(node->right, 2 * val + 2);
    }

public:
    // 构造函数：恢复树
    FindElements(TreeNode* root) {
        if (root != nullptr) recover(root, 0);
    }

    // 查找目标值是否存在
    bool find(int target) {
        return values.find(target) != values.end();
    }
};

