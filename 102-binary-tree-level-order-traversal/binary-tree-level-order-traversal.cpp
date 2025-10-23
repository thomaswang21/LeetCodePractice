class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level = q.size();            // 当前层的节点数量
            vector<int> levelNodes;          // 存放这一层的所有节点值

            while (level > 0) {              // 遍历当前层的所有节点
                auto node = q.front();
                q.pop();

                levelNodes.push_back(node->val);

                if (node->left) q.push(node->left);    // 加入下一层的节点
                if (node->right) q.push(node->right);

                level--;                      // 处理完一个节点，层数计数减一
            }

            ans.push_back(levelNodes);        // 当前层遍历结束，加入结果
        }

        return ans;
    }
};

