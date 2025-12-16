class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        // 标准 BFS 算法框架
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (arr[cur] == 0) {
                return true;
            }
            // 往左跳
            int left = cur - arr[cur];
            if (left >= 0 && !visited[left]) {
                q.push(left);
                visited[left] = true;
            }
            // 往右跳
            int right = cur + arr[cur];
            if (right < arr.size() && !visited[right]) {
                q.push(right);
                visited[right] = true;
            }
        }
        return false;
    }
};