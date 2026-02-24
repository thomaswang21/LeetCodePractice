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
    int dfs(TreeNode* root, int minv, int maxv) {
        if (!root) return -1;
        int val = root->val;
        int res = max(abs(val - minv), abs(val - maxv));
        minv = min(minv, val);
        maxv = max(maxv, val);
        res = max(res, dfs(root->left, minv, maxv));
        res = max(res, dfs(root->right, minv, maxv));
        return res;
    }

    int maxAncestorDiff(TreeNode* root) {
        int val = root->val;
        return max(dfs(root->left, val, val), dfs(root->right, val, val));
    }
};

