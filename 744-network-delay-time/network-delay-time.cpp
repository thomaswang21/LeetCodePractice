#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

/**
 * 题目：网络延迟时间（Network Delay Time）
 * 思路：使用 Dijkstra 算法计算从起点 k 出发到所有节点的最短路径，
 *      然后返回到达所有节点的最长时间（即最慢信号到达时间）。
 *      若存在无法到达的节点，则返回 -1。
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // ---------- 1. 建图 ----------
        // 图的表示：使用邻接表（unordered_map<int, vector<pair<int, int>>>）
        // graph[u] = {{v1, w1}, {v2, w2}, ...}
        // 表示从节点 u 出发，有若干条边到节点 vi，权重为 wi。
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& t : times)
            graph[t[0]].push_back({t[1], t[2]});  // t[0] -> t[1]  花费 t[2]

        // ---------- 2. 初始化距离数组 ----------
        // dist[i] 表示从起点 k 到节点 i 的最短距离
        // 初始化为无穷大（INT_MAX），表示尚未可达
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;  // 起点到自身距离为 0

        // ---------- 3. 使用优先队列（最小堆） ----------
        // 存储 pair<当前耗时, 节点>
        // 优先按照耗时最小的节点出队（保证每次取出的是“当前最短路径”节点）
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});  // 起点 k，耗时为 0

        // ---------- 4. Dijkstra 主循环 ----------
        while (!pq.empty()) {
            auto [time, node] = pq.top(); // 当前节点及其最短时间
            pq.pop();

            // 若当前路径比已知的最短路径更长，则跳过（已访问过更优解）
            if (time > dist[node]) continue;

            // 遍历所有邻居节点
            for (auto& [nei, w] : graph[node]) {
                int newTime = time + w; // 从当前节点到邻居节点的新耗时
                // 若找到更短路径，则更新并压入堆
                if (newTime < dist[nei]) {
                    dist[nei] = newTime;
                    pq.push({newTime, nei});
                }
            }
        }

        // ---------- 5. 计算最终结果 ----------
        // 找出所有节点的最大最短距离（即信号传播到最后一个节点的时间）
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1; // 若有节点不可达
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};

