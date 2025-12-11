class Solution {
private:
    bool ok = true;
    vector<bool> color;
    vector<bool> visited;

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // 图节点编号从 1 开始
        color.resize(n + 2);
        visited.resize(n + 1);
        // 转化成邻接表表示图结构
        vector<vector<int>> graph = buildGraph(n, dislikes);

        for (int v = 1; v <= n; v++) {
            if (!visited[v]) {
                traverse(graph, v);
            }
        }
        return ok;
    }

private:
    // 建图函数
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& dislikes) {
        // 图节点编号为 1...n
        vector<vector<int>> graph(n + 1);
        for (const auto& edge : dislikes) {
            int v = edge[1];
            int w = edge[0];
            // 「无向图」相当于「双向图」
            // v -> w
            graph[v].push_back(w);
            // w -> v
            graph[w].push_back(v);
        }
        return graph;
    }

    // 和之前判定二分图的 traverse 函数完全相同
    void traverse(const vector<vector<int>>& graph, int v) {
        if (!ok) return;
        visited[v] = true;
        for (int w : graph[v]) {
            if (!visited[w]) {
                color[w] = !color[v];
                traverse(graph, w);
            } else {
                if (color[w] == color[v]) {
                    ok = false;
                }
            }
        }
    }
};