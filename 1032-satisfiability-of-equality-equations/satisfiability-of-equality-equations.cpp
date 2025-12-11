#include <vector>
#include <string>

using namespace std;

class UnionFind {
private:
    // 记录连通分量个数
    int count;
    // 存储若干棵树
    vector<int> parent;
    // 记录树的“重量”
    vector<int> size;

public:
    UnionFind(int n) : count(n), parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // 将 p 和 q 连通
    void unionSets(int p, int q) {
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

    int countComponents() {
        return count;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // 26 个英文字母
        UnionFind uf(26);
        // 先让相等的字母形成连通分量
        for (string eq : equations) {
            if (eq[1] == '=') {
                char x = eq[0];
                char y = eq[3];
                uf.unionSets(x - 'a', y - 'a');
            }
        }
        // 检查不等关系是否打破相等关系的连通性
        for (string eq : equations) {
            if (eq[1] == '!') {
                char x = eq[0];
                char y = eq[3];
                // 如果相等关系成立，就是逻辑冲突
                if (uf.connected(x - 'a', y - 'a'))
                    return false;
            }
        }
        return true;
    }
};