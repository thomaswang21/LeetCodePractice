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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
    TreeNode*dfs(vector<int>nums, int l, int r ){
        if(l>r) return NULL;
        int id=l;
        for(int i=l+1; i<=r;i++)
            if(nums[i]>nums[id])
            id=i;
        TreeNode*res=new TreeNode(nums[id]);
        res->left=dfs(nums, l, id-1);
        res->right=dfs(nums, id+1,r);
        return res;
        }
    
};