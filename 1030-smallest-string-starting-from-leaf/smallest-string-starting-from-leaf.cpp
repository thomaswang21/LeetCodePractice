class Solution {
public:
    string ans, path;

    void dfs(TreeNode* root) {
        if (!root) return;
        path += root->val + 'a';

        if (!root->left && !root->right) {
            reverse(path.begin(), path.end());
            if (ans.empty() || ans > path) ans = path;
            reverse(path.begin(), path.end());
        } else {
            dfs(root->left);
            dfs(root->right);
        }

        path.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

