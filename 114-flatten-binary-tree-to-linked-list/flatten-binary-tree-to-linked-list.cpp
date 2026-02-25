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

// 思路：
// 题目要求将二叉树原地展开成链表，顺序为前序遍历
// 我们可以使用递归后序遍历的方式，从右子树、左子树到当前节点
// 每次将当前节点的右指针指向上一个访问的节点（pre）
// 并将左指针置空
// 这样可以在不使用额外空间的情况下完成展开



class Solution {
public:
    TreeNode* pre = NULL; // 记录上一个访问的节点

    void flatten(TreeNode* root) {
        if (root == NULL) return;
        // 递归展开右子树
        flatten(root->right);
        // 递归展开左子树
        flatten(root->left);
        // 当前节点的右指针指向上一个访问的节点
        root->right = pre;
        // 左指针置空
        root->left = NULL;
        // 更新上一个访问的节点
        pre = root;
    }
};

