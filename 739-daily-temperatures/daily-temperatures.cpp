class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        // 这里放元素索引，而不是元素
        stack<int> s;
        // 单调栈模板
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            // 得到索引间距
            if (s.empty()) {
                res[i] = 0;
            } else {
                res[i] = s.top() - i;
            }
            // 将索引入栈，而不是元素
            s.push(i); 
        }
        return res;
    }
};