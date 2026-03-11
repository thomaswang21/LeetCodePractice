
// 思路：使用并查集（Union-Find）算法来计算无向图中的连通分量数量
// 1. 初始化每个节点的父节点为自己
// 2. 对每条边执行合并操作（union）
// 3. 统计最终有多少个独立的根节点（即连通分量数）
// 时间复杂度：O(n + e * α(n))，其中 α(n) 是阿克曼函数的反函数，近似常数
// 空间复杂度：O(n)

// 示例：
// n = 5, edges = [[0,1],[1,2],[3,4]]
// 初始父节点: [0,1,2,3,4]
// 合并(0,1): [0,0,2,3,4]
// 合并(1,2): [0,0,0,3,4]
// 合并(3,4): [0,0,0,3,3]
// 根节点为 {0,3}，连通分量数 = 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 查找函数，带路径压缩
    int findParent(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = findParent(parent[x], parent); // 路径压缩
        }
        return parent[x];
    }

    // 合并函数
    void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = findParent(a, parent);
        int pb = findParent(b, parent);
        if (pa != pb) {
            if (rank[pa] < rank[pb]) {
                parent[pa] = pb;
            } else if (rank[pa] > rank[pb]) {
                parent[pb] = pa;
            } else {
                parent[pb] = pa;
                rank[pa]++;
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto& e : edges) {
            unionSet(e[0], e[1], parent, rank);
        }

        unordered_set<int> roots;
        for (int i = 0; i < n; i++) {
            roots.insert(findParent(i, parent));
        }

        return roots.size();
    }
};
