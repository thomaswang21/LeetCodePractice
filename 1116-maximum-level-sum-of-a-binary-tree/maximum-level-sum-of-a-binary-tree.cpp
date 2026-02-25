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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        // 记录 BFS 走到的层数
        int depth = 1;
        // 记录元素和最大的那一行和最大元素和
        int res = 0, maxSum = INT_MIN;

        while (!q.empty()) {
            int sz = q.size();
            int levelSum = 0;
            // 遍历这一层
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                levelSum += cur->val;

                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            if (levelSum > maxSum) {
                // 更新最大元素和
                res = depth;
                maxSum = levelSum;
            }
            depth++;
        }
        return res;
    }
};