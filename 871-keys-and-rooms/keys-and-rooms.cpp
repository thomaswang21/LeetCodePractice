

// BFS 解法
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        // 记录访问过的房间
        vector<bool> visited(n, false);
        queue<int> queue;
        // 在队列中加入起点，启动 BFS
        queue.push(0);
        visited[0] = true;

        while (!queue.empty()) {
            int room = queue.front();
            queue.pop();
            for (int nextRoom : rooms[room]) {
                if (!visited[nextRoom]) {
                    visited[nextRoom] = true;
                    queue.push(nextRoom);
                }
            }
        }

        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};