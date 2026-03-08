

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n + 1, 0);
        // 计算后缀和
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        unordered_map<long long, int> memo;

        // 递归函数 dfs(i, M)
        function<int(int, int)> dfs = [&](int i, int M) {
            if (i >= n) return 0;
            long long key = ((long long)i << 10) + M; // 合并索引和M作为key
            if (memo.find(key) != memo.end()) return memo[key];
            if (i + 2 * M >= n) return memo[key] = suffixSum[i]; // 可以拿完所有石子

            int best = 0;
            // 尝试取x堆石子
            for (int x = 1; x <= 2 * M; x++) {
                int opponent = dfs(i + x, M > x ? M : x);
                int current = suffixSum[i] - opponent;
                if (current > best) best = current;
            }
            memo[key] = best;
            return best;
        };

        return dfs(0, 1);
    }
};

