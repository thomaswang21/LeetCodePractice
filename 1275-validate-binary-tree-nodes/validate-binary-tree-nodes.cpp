// 用 Union Find 算法判断
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // 记录每个节点的入度
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                indegree[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
            }
        }
        // 按道理应该有且只有根节点的入度为 0，
        // 其他节点的入度都必须为 1
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) {
                    // 有多个入度为 0 的节点
                    return false;
                }
                root = i;
            } else if (indegree[i] != 1) {
                // 除了根节点外其他节点的入度都必须为 1
                return false;
            }
        }

        // 如果没有根节点，那肯定不是合法二叉树
        if (root == -1) {
            return false;
        }

        // 启动 Union-Find 并查集算法，
        // 保证树中只有一个联通分量且不成环
        UF uf(n);
        for (int i = 0; i < n; i++) {
            int left = leftChild[i];
            int right = rightChild[i];

            if (left != -1) {
                if (uf.connected(i, left)) {
                    // 成环
                    return false;
                }
                uf.unionNodes(i, left);
            }
            if (right != -1) {
                if (uf.connected(i, right)) {
                    // 成环
                    return false;
                }
                uf.unionNodes(i, right);
            }
        }
        // 要保证只有一个连通分量
        return uf.getCount() == 1;
    }

    class UF {
    public:
        // 记录连通分量个数
        int count;
        // 存储若干棵树
        vector<int> parent;
        // 记录树的“重量”
        vector<int> size;

        UF(int n) {
            count = n;
            parent.resize(n);
            size.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        // 将 p 和 q 连通
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
            count--;
        }

        // 判断 p 和 q 是否互相连通
        bool connected(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            // 处于同一棵树上的节点，相互连通
            return rootP == rootQ;
        }

        // 返回节点 x 的根节点
        int find(int x) {
            while (parent[x] != x) {
                // 进行路径压缩
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        int getCount() {
            return count;
        }
    };
};

