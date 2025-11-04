class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses, 0);

        // 1. 构建图和初始化先修矩阵
        for (auto& e : prerequisites) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            indegree[v]++;
            isPre[u][v] = true; // 直接先修关系
        }

        // 2. 拓扑排序 + 传递闭包
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);

                // 对所有 x，如果 x 是 u 的先修课，那么 x 也是 v 的先修课
                for (int x = 0; x < numCourses; ++x) {
                    if (isPre[x][u]) {
                        isPre[x][v] = true;
                    }
                }
            }
        }

        // 3. 回答 queries
        vector<bool> res;
        for (auto& q : queries) {
            res.push_back(isPre[q[0]][q[1]]);
        }
        return res;
    }
};