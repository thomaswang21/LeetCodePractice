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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res;
        while(q.size())
        {
            int len=q.size();
            res=q.front()->val;//每一层的第一个节点
            while(len--)
            {
                auto t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }

        }
        return res;
    }
};

