#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

/**
 * 题目：787. K 次中转以内的最便宜机票
 * 思路：
 *   这是带“最多 K 次中转”的最短路问题。
 *   不能用传统 Dijkstra，因为 Dijkstra 不支持“限制边数”。
 *
 *   正确方法：使用带状态的 BFS / Dijkstra（优先队列）
 *   状态：{当前价格, 当前城市, 已用中转数}
 *
 *   每次松弛时必须保证中转次数 <= k + 1（飞行次数 = 中转 + 1）
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // ---------- 1. 建图 ----------
        // graph[u] = { {v1, w1}, {v2, w2}, ... }
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& f : flights)
            graph[f[0]].push_back({f[1], f[2]});

        // ---------- 2. dist 数组 ----------
        // dist[city][stops] = 在使用 stops 次中转情况下，到达 city 的最小费用
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        // ---------- 3. 使用优先队列（最小堆） ----------
        // 元素格式：{当前花费, 当前城市, 已经使用的中转次数}
        priority_queue<
            tuple<int,int,int>,               // {cost, city, stops}
            vector<tuple<int,int,int>>,
            greater<>
        > pq;

        pq.push({0, src, 0});

        // ---------- 4. Dijkstra 带状态主循环 ----------
        while (!pq.empty()) {
            auto [cost, city, stops] = pq.top();
            pq.pop();

            // 如果已经到达目的地，直接返回最小花费
            if (city == dst) return cost;

            // 如果中转次数超过限制，则不能继续扩展
            if (stops == k + 1) continue;

            // 遍历所有下一跳
            for (auto& [nextCity, price] : graph[city]) {
                int newCost = cost + price;

                // 如果更便宜，则更新，并继续扩展下一层
                if (newCost < dist[nextCity][stops + 1]) {
                    dist[nextCity][stops + 1] = newCost;
                    pq.push({newCost, nextCity, stops + 1});
                }
            }
        }

        // ---------- 5. 最终结果 ----------
        int ans = INT_MAX;
        // 在 0 ~ k+1 次中转范围内，找最小花费
        for (int i = 0; i <= k + 1; i++)
            ans = min(ans, dist[dst][i]);

        return ans == INT_MAX ? -1 : ans;
    }
};
