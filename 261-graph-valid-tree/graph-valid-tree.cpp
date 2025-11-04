class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 初始化 0...n-1 共 n 个节点
        UF uf(n);
        // 遍历所有边，将组成边的两个节点进行连接
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // 若两个节点已经在同一连通分量中，会产生环
            if (uf.connected(u, v)) {
                return false;
            }
            // 这条边不会产生环，可以是树的一部分
            uf.unionNodes(u, v);
        }
        // 要保证最后只形成了一棵树，即只有一个连通分量
        return uf.getCount() == 1;
    }

private:
    class UF {
    public:
        // 连通分量个数
        int count;
        // 存储一棵树
        vector<int> parent;
        // 记录树的「重量」
        vector<int> size;

        // n 为图中节点的个数
       UF(int n) {
    count = n;
    parent = vector<int>(n);
    size = vector<int>(n, 1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}


        // 将节点 p 和节点 q 连通
        void unionNodes(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ)
                return;

            // 小树接到大树下面，较平衡
            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            // 两个连通分量合并成一个连通分量
            --count;
        }

        // 判断节点 p 和节点 q 是否连通
        bool connected(int p, int q) {
            return find(p) == find(q);
        }

        // 返回图中的连通分量个数
        int getCount() const {
            return count;
        }

    private:
        // 返回节点 x 的连通分量根节点
        int find(int x) {
            while (parent[x] != x) {
                // 进行路径压缩
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }
    };
};