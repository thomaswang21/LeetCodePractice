class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (int x : stones) sum += x;

    int target = sum / 2;
    vector<int> dp(target + 1, 0);

    for (int w : stones) {
        for (int j = target; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + w);
        }
    }

    return sum - 2 * dp[target];
}

};