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
    int res;
    int pathSum(TreeNode* root, long long sum) {
        if(!root) return 0;
        dfs(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return res;
    }
    void dfs(TreeNode* root,long long sum)
    {
        if(!root) return;
        sum -= root->val;
        if(!sum) res++;
        if(root->left) dfs(root->left,sum);
        if(root->right) dfs(root->right,sum);
    }
};



