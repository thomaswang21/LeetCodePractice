

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // 队列用于层序遍历
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val; // 初始化答案为根节点值

        while (!q.empty()) {
            int size = q.size(); // 当前层节点数
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                // 当前层第一个节点更新答案
                if (i == 0) ans = node->val;
                // 先左后右入队
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

