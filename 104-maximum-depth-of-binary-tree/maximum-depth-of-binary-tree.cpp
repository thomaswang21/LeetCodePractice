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
    int maxDepth(TreeNode* root) {
        // 如果节点为空，深度为0
        if (root == nullptr) {
            return 0;
        }
        // 递归计算左右子树的深度
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        // 返回较大深度加1
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }
};

