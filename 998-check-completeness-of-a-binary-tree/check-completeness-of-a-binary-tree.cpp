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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true; // if the root is null, then the tree is complete
        queue<TreeNode*>q;
        q.push(root);
        bool nullSeen=false; // flag that keeps track of whether we encountered a null node previously or not

        while(!q.empty()){ 
            int levelSize=q.size(); // number of nodes at this level
            while(levelSize--){    
                TreeNode* tp=q.front();
                q.pop();
                if(!tp) nullSeen=true; // if the node is null, set the nullSeen flag to true 
                else{
                    if(nullSeen) return false; // if we already had a null node, then this binary tree is not complete
                    q.push(tp->left);
                    q.push(tp->right);
                }
            }
        }
        return true;
    }
};