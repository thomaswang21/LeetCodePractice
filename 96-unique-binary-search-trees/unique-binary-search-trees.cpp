class Solution {
public:
    int numTrees(int n) {
        vector<int>f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i ++ )
        {
            f[i] = 0;
            for (int j = 1; j <= i; j ++ )
                f[i] += f[j - 1] * f[i - j];
        }
        return f[n];
    }
};