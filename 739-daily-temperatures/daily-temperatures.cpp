class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // Initialize answer vector with 0s. 
        // Days with no future warmer temp will remain 0.
        vector<int> answer(n, 0); 
        stack<int> st; // Stores indices, not temperatures

        for (int i = 0; i < n; ++i) {
            // While stack is not empty AND current temp is warmer than the temp at the top index
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                
                // The difference in indices is the number of days waited
                answer[prevIndex] = i - prevIndex;
            }
            // Push current index to stack to find its next warmer day later
            st.push(i);
        }

        return answer;
    }
};
