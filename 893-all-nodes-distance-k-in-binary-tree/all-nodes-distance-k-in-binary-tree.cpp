

// 主体思路：DFS 建立父节点映射 + BFS 扩展距离
class Solution {
public:
    // 建立父节点映射 O(N)
    void buildParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (node == NULL) return;
        if (node->left) {
            parent[node->left] = node;
            buildParent(node->left, parent);
        }
        if (node->right) {
            parent[node->right] = node;
            buildParent(node->right, parent);
        }
    }

    // 主函数 O(N)
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent; // 存储父节点
        buildParent(root, parent); // 建立父节点映射

        unordered_set<TreeNode*> visited; // 记录访问过的节点
        queue<TreeNode*> q; // BFS 队列
        q.push(target);
        visited.insert(target);

        int dist = 0; // 当前层距离

        // BFS 层序遍历
        while (!q.empty()) {
            int size = q.size();
            if (dist == k) break; // 到达距离 k 停止扩展

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // 向左扩展
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                // 向右扩展
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                // 向父节点扩展
                if (parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end()) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            dist++;
        }

        // 收集所有距离为 k 的节点值
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};