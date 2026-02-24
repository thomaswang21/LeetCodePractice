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
    string ans;

    string tree2str(TreeNode* t) {
        dfs(t);
        return ans;
    }

    void dfs(TreeNode* t) {
        if (!t) return;
        ans += to_string(t->val);
        if (t->left ||t->right) {
            ans += '(';
            dfs(t->left);
            ans += ')';
        }
        if (t->right) {
            ans += '(';
            dfs(t->right);
            ans += ')';
        }
    }
};
