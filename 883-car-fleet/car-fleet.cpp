

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<vector<int>> cars(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }
        // 按照初始位置，从小到大排序
        sort(cars.begin(), cars.end());
        
        // 计算每辆车到达终点的时间
        vector<double> time(n);
        for (int i = 0; i < n; i++) {
            int pos = cars[i][0];
            int vel = cars[i][1];
            time[i] = (double)(target - pos) / vel;
        }
        
        // 使用单调栈计算车队的数量
        // 避免使用栈模拟，倒序遍历取递增序列就是答案
        int res = 0;
        double maxTime = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (time[i] > maxTime) {
                maxTime = time[i];
                res++;
            }
        }
        return res;
    }
};