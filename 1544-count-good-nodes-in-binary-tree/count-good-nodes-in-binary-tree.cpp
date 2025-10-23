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
    int ans=0;
public:
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        dfs(root,root->val);
        return ans;
    }
    void dfs(TreeNode*root,int curr){
        if(root==NULL){
            return;
        }
        if(root->val>=curr){
            curr=root->val;
            ans++;
        }
        dfs(root->left,curr);
        dfs(root->right,curr);
    }
};