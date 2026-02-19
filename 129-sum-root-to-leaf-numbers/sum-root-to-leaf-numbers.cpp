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

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* u, int s)
    {
        if (!u) return ;
        s = s * 10 + u->val;
        if (u->left) dfs(u->left, s);
        if (u->right) dfs(u->right, s);
        if (!u->left && !u->right) ans += s;
    }
};

