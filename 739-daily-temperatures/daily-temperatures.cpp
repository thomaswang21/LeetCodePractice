class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> s; // 存索引

        for (int i = 0; i < n; i++) {
            // 当前温度大于栈顶索引对应的温度
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int idx = s.top();
                s.pop();
                res[idx] = i - idx; // 更新栈顶元素的等待天数
            }
            s.push(i); // 当前元素入栈
        }

        return res;
    }
};


