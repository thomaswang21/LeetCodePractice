class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> target = {{1,1,1},{1,1,1},{1,1,1}};
        if (grid == target) return 0;

        queue<pair<vector<vector<int>>, int>> q;
        set<vector<vector<int>>> visited;

        q.push({grid, 0});
        visited.insert(grid);

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!q.empty()) {
            auto [curGrid, steps] = q.front();
            q.pop();

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (curGrid[i][j] > 1) {
                        for (auto& d : dirs) {
                            int ni = i + d[0], nj = j + d[1];
                            if (ni >=0 && ni <3 && nj >=0 && nj <3) {
                                auto nextGrid = curGrid;
                                nextGrid[i][j]--;
                                nextGrid[ni][nj]++;

                                if (nextGrid == target) return steps + 1;

                                if (!visited.count(nextGrid)) {
                                    visited.insert(nextGrid);
                                    q.push({nextGrid, steps + 1});
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};
