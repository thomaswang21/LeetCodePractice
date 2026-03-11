

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st; // 单调递减栈，存储右边人的身高

        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            // 弹出所有比当前人矮的人
            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
                count++;
            }
            // 如果栈不为空，说明还能看到一个更高的人
            if (!st.empty()) count++;
            ans[i] = count;
            st.push(heights[i]);
        }
        return ans;
    }
};

