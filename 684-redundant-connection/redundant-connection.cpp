#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF uf(n + 1); // 注意：节点编号从 1 开始，所以要 n+1

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (uf.connected(u, v)) {
                return edge; // 发现环，返回当前边
            }
            uf.unionNodes(u, v);
        }
        return {};
    }

private:
    class UF {
    public:
        vector<int> parent;
        vector<int> size;

        UF(int n) {
            parent = vector<int>(n);
            size = vector<int>(n, 1);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]]; // 路径压缩
                x = parent[x];
            }
            return x;
        }

        bool connected(int p, int q) {
            return find(p) == find(q);
        }

        void unionNodes(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ) return;

            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
        }
    };
};
