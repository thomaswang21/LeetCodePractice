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
    vector<int> values;

    void getAllValues(TreeNode* root){
        if(root == nullptr){
            return;
        }
        getAllValues(root->left);
        values.emplace_back(root->val);
        getAllValues(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        getAllValues(root);
        int n = values.size();
        int l = 0, r = n - 1;
        while(l < r){
            int tmp = values[l] + values[r];
            if(tmp == k){
                return true;
            } else if(tmp > k){
                r--;
            } else {
                l++;
            }
        }
        return false;
    }
};

