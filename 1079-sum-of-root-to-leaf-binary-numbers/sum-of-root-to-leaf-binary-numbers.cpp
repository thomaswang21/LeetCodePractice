
class Solution {
public:
    int dfs(TreeNode* root, int x) {
        x = x * 2 + root->val;
        if (!root->left && !root->right) return x;
        int res = 0;
        if (root->left) res += dfs(root->left, x);
        if (root->right) res += dfs(root->right, x);
        return res;
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};

