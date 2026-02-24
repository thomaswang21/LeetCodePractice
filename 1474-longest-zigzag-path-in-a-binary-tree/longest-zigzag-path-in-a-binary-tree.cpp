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
    int ans = 0;

    void dfs(TreeNode* node, bool goLeft, int length) {
        if (!node) return;

        ans = max(ans, length);

        if (goLeft) {
            // 上一步往左，这一步必须往右
            dfs(node->right, false, length + 1);
            // 重新开始
            dfs(node->left, true, 1);
        } else {
            // 上一步往右，这一步必须往左
            dfs(node->left, true, length + 1);
            // 重新开始
            dfs(node->right, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root->left, true, 1);
        dfs(root->right, false, 1);
        return ans;
    }
};