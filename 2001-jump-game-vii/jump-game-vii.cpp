class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> can(n, false);
        can[0] = true;

        int farthest = 0; // 表示我们最远检查到哪里了

        for (int i = 0; i < n; i++) {
            if (!can[i]) continue;  // 不能从这里跳，跳过

            // 下一个可以尝试 reach 的区间是：
            // [i + minJump, i + maxJump]
            int l = i + minJump;
            int r = min(i + maxJump, n - 1);

            // 我们只从 farthest+1 开始扫描，避免重复
            int start = max(farthest + 1, l);

            for (int j = start; j <= r; j++) {
                if (s[j] == '0') can[j] = true;
            }

            // 更新扫描到的最远位置
            farthest = max(farthest, r);

            // 如果已经能到最后一个位置，直接返回
            if (can[n - 1]) return true;
        }
        return can[n - 1];
    }
};
