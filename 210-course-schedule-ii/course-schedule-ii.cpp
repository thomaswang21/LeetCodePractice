class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); // 邻接表
        vector<int> indegree(numCourses);      // 入度数组

        // 建图: 先学b再学a，所以边是 b -> a
        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            graph[b].push_back(a); // b -> a
            indegree[a]++;         // a的入度加一
        }

        queue<int> q;
        // 把所有入度为0的课入队
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order; // 记录学习顺序

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course); // 加入学习顺序

            for (int next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // 如果能学完所有课程，则返回顺序，否则返回空数组
        if (order.size() == numCourses) {
            return order;
        } else {
            return {};
        }
    }
};
