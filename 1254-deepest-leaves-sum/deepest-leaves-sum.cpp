#include <queue>

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr) return 0;
        std::queue<TreeNode*> q;
        q.push(root);

        int sum = 0;
        while (!q.empty()) {
            sum = 0;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                // 累加一层的节点之和
                sum += cur->val;
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
        }
        // 现在就是最后一层的节点值和
        return sum;
    }
};