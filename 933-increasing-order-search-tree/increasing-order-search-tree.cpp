class Solution {
public:
    TreeNode* tail;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);

        tail->right = root;
tail = root;

        root->left = NULL;

        dfs(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        auto dummy = new TreeNode();
        tail = dummy;
        dfs(root);
        return dummy->right;
    }
};

