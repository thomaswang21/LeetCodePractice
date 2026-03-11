

// 并查集类
class UnionFind {
public:
    vector<int> parent;
    UnionFind() {
        parent.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i; // 初始化每个节点的父节点为自己
        }
    }

    // 查找函数，带路径压缩
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    // 合并两个集合
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY; // 合并
        }
    }

    // 判断是否在同一集合
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;

        // 第一步：处理所有 "==" 等式
        for (auto& eq : equations) {
            if (eq[1] == '=') { // "=="
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                uf.unite(a, b);
            }
        }

        // 第二步：处理所有 "!=" 不等式
        for (auto& eq : equations) {
            if (eq[1] == '!') { // "!="
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                if (uf.connected(a, b)) {
                    return false; // 矛盾，返回false
                }
            }
        }

        return true; // 所有条件都满足
    }
};


