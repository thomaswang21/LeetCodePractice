/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    int maxc = 0, curc = 0, last;

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (!curc || root->val == last) {
            curc ++;
            last = root->val;
        } else {
            last = root->val;
            curc = 1;
        }
        if (curc > maxc) ans = {last}, maxc = curc;
        else if (curc == maxc) ans.push_back(last);
        dfs(root->right);
    }
};

