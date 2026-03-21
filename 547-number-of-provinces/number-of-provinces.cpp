

#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rankv;

    // 构造函数 O(n)
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // 查找根节点 O(α(n))
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    // 合并两个集合 O(α(n))
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            if (rankv[px] < rankv[py]) {
                parent[px] = py;
            } else if (rankv[px] > rankv[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rankv[px]++;
            }
        }
    }
};

class Solution {
public:
    // 主函数 O(n^2 * α(n))
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    dsu.unite(i, j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) count++;
        }
        return count;
    }
};

