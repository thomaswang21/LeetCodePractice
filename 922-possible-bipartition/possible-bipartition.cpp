class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        color.resize(n + 1);
        visited.resize(n + 1);
        vector<vector<int>> graph = buildGraph(n, dislikes);

        for (int v = 1; v <= n; v++) {
            if (!visited[v]) {
                traverse(graph, v);
            }
        }
        return ok;
    }

private:
    bool ok = true;                 // 图是否可以二分
    vector<bool> color;             // 节点颜色
    vector<bool> visited;           // 是否访问过

    // 构建邻接表（无向图）
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto &edge : dislikes) {
            int v = edge[0];
            int w = edge[1];
            graph[v].push_back(w);
            graph[w].push_back(v);   // 无向边
        }
        return graph;
    }

    // DFS 遍历并染色
    void traverse(const vector<vector<int>>& graph, int v) {
        if (!ok) return;            // 一旦发现冲突，立即停止
        visited[v] = true;

        for (int w : graph[v]) {
            if (!visited[w]) {
                color[w] = !color[v];   // 相邻节点染相反颜色
                traverse(graph, w);     // 正确递归调用
            } else {
                if (color[w] == color[v]) {  // 相邻节点颜色相同 -> 冲突
                    ok = false;
                }
            }
        }
    }
};