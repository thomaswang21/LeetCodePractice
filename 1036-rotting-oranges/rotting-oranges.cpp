class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty() && fresh > 0) {
            int length = q.size();
            for(int i = 0; i < length; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop(); // ✅ 别忘了 pop

                for(int k = 0; k < 4; k++) {
                    int row = r + direction[k][0];
                    int col = c + direction[k][1];
                    if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            time++; // ✅ 每分钟腐烂一层，才 +1
        }

                    if (fresh == 0) {
                    return time;
                } else {
                    return -1;
                }

                    }
    };