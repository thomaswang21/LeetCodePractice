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
#include <queue>
#include <climits>

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 0; // 根节点是第0层
        
        while (!q.empty()) {
            int sz = q.size();
            int prev;
            // 根据层号初始化 prev 用于单调比较
            if (level % 2 == 0) prev = 0;          // 偶数层严格递增，最小值设为0
            else prev = INT_MAX;                    // 奇数层严格递减，最大值设为 INT_MAX
            
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                
                int val = node->val;
                
                // 检查奇偶性
                if (level % 2 == 0) {
                    // 偶数层，值必须是奇数
                    if (val % 2 == 0) return false;
                    // 严格递增
                    if (val <= prev) return false;
                } else {
                    // 奇数层，值必须是偶数
                    if (val % 2 != 0) return false;
                    // 严格递减
                    if (val >= prev) return false;
                }
                
                prev = val; // 更新 prev
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            level++; // 下一层
        }
        
        return true;
    }
};