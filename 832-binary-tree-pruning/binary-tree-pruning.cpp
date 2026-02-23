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
    TreeNode* pruneTree(TreeNode* root) {
        if (!dfs(root)) return NULL;
        return root;
    }

    bool dfs(TreeNode* root) {
        if (!root) return false;
        if (!dfs(root->left)) root->left = NULL;
        if (!dfs(root->right)) root->right = NULL;
        return root->val || root->left || root->right;
    }
};

