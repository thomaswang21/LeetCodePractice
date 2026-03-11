

class Solution {
public:
    // 并查集父节点数组
    vector<int> parent;

    // 查找函数（带路径压缩）
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    // 合并函数
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return false; // 如果已经在同一集合中，说明形成环
        }
        parent[py] = px; // 合并集合
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i; // 初始化父节点
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!unite(u, v)) {
                return edge; // 找到形成环的边
            }
        }
        return {};
    }
};

