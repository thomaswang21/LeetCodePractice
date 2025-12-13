class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            // base case，只有一个节点 0 的话，无法形成边，所以直接返回节点 0
            return {0};
        }
        // 1、构建邻接表
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            // 无向图，等同于双向图
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // 2、找到所有的叶子节点
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) {
                q.push(i);
            }
        }

        // 3、不断删除叶子节点，直到剩下的节点数小于等于 2 个
        int nodeCount = n;
        while (nodeCount > 2) {
            int sz = q.size();
            nodeCount -= sz;
            for (int i = 0; i < sz; ++i) {
                // 删除当前叶子节点
                int cur = q.front();
                q.pop();

                // 找到与当前叶子节点相连的节点
                for (int neighbor : graph[cur]) {
                    // 将被删除的叶子节点的邻接节点的度减 1
                    auto it = find(graph[neighbor].begin(), graph[neighbor].end(), cur);
                    if (it != graph[neighbor].end()) {
                        graph[neighbor].erase(it);
                    }
                    // 如果删除后，相连节点的度为 1，说明它也变成了叶子节点
                    if (graph[neighbor].size() == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // 4、最后剩下的节点就是根节点
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};