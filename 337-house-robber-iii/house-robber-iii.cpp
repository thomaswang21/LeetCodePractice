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
    int rob(TreeNode* root) {
        vector<int> f=dfs(root);
        return max(f[0], f[1]);
    }
    vector<int>dfs(TreeNode*u){
        if(!u)return {0,0};
        vector<int>f(2,0);
        auto l=dfs(u->left), r=dfs(u->right);
        f[0]=max(l[0],l[1])+max(r[0],r[1]);
        f[1]=l[0]+r[0]+u->val;
        return f;
    }
};