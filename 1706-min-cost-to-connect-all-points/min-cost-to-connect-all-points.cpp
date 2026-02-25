
// 思路：本题是最小生成树问题（Minimum Spanning Tree, MST）
// 1. 每个点是一个节点，边的权值为两点间的曼哈顿距离
// 2. 目标是用最小代价连接所有点
// 3. 可用 Prim 算法实现：每次选择当前未加入集合的点中，与已加入集合的点距离最小的那个点加入集合
// 4. 时间复杂度 O(n^2)，适合 n <= 1000 的情况

#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX); // 记录每个点到生成树的最小距离
        vector<bool> inMST(n, false);    // 标记点是否已加入生成树
        minDist[0] = 0;                  // 从第一个点开始
        int result = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;
            int minVal = INT_MAX;

            // 找到未加入生成树的点中距离最小的点
            for (int j = 0; j < n; j++) {
                if (!inMST[j] && minDist[j] < minVal) {
                    minVal = minDist[j];
                    u = j;
                }
            }

            inMST[u] = true;
            result += minVal;

            // 更新其他点到生成树的最小距离
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                    }
                }
            }
        }
        return result;
    }
};


