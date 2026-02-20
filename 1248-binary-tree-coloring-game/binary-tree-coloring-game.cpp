/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int n;

    bool btreeGameWinningMove(TreeNode* root, int _n, int x) {
        n = _n;
        dfs(root, x);
        return ans > n - ans;
    }

    int dfs(TreeNode* root, int x) {
        if (!root) return 0;
        if (root->val == x) {
            int left = dfs(root->left, x);
            int right = dfs(root->right, x);
            ans = max({ans, left, right, n - left - right - 1});
            return left + right + 1;
        } else {
            return dfs(root->left, x) + dfs(root->right, x) + 1;
        }
    }
};

