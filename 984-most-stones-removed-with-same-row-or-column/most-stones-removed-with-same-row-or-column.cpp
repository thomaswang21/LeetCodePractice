// union find 算法模板
class UF {
private:
    // 连通分量个数
    int cnt;
    // 存储每个节点的父节点
    vector<int> parent;

public:
    // n 为图中节点的个数
    UF(int n) : cnt(n), parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // 将节点 p 和节点 q 连通
    void unionSets(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ) {
            return;
        }

        parent[rootQ] = rootP;
        // 两个连通分量合并成一个连通分量
        cnt--;
    }

    // 判断节点 p 和节点 q 是否连通
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 返回图中的连通分量个数
    int count() {
        return cnt;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        // 一维坐标 -> 节点 ID
        unordered_map<int, int> codeToId;
        for (int i = 0; i < n; i++) {
            codeToId[encode(stones[i])] = i;
        }

        // 记录每一行每一列有哪些节点
        unordered_map<int, vector<int>> colIndexToCodes;
        unordered_map<int, vector<int>> rowIndexToCodes;
        for (const auto& point : stones) {
            int x = point[0], y = point[1];
            rowIndexToCodes[x].push_back(encode(point));
            colIndexToCodes[y].push_back(encode(point));
        }

        // 启动 union find 算法
        UF uf(n);

        // 把每一列的节点连通
        for (const auto& [index, col] : colIndexToCodes) {
            int firstId = codeToId[col[0]];
            for (int i = 1; i < col.size(); i++) {
                int otherId = codeToId[col[i]];
                uf.unionSets(firstId, otherId);
            }
        }

        // 把每一行的节点连通
        for (const auto& [index, row] : rowIndexToCodes) {
            int firstId = codeToId[row[0]];
            for (int i = 1; i < row.size(); i++) {
                int otherId = codeToId[row[i]];
                uf.unionSets(firstId, otherId);
            }
        }
        // 石头总数 - 连通分量数量就是被消除的石头个数
        return n - uf.count();
    }

    // 将二维坐标转化成一维索引
    int encode(const vector<int>& point) {
        return point[0] * 10000 + point[1];
    }

};