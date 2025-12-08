class Solution {
public:
    vector<vector<int>> s;

    int get(int x1, int y1, int x2, int y2) {
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size();
        s = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i - 1][j - 1];
            }
        }

        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) { 
                res[i - 1][j - 1] = get(max(i - k, 1), max(j - k, 1), min(n, i + k), min(m, j + k));
            }
        }

        return res;
    }
};

