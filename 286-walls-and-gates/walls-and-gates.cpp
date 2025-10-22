class Solution {
public:
    int rows;
    int cols;
    void wallsAndGates(vector<vector<int>>&grid) {
        rows=grid.size();
        cols=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
                
            }
        }
        vector<vector<int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r=row+dirs[i][0];
                int c=col+dirs[i][1];
                 
                if (r < 0 || r >= rows || c < 0 || 
                    c >= cols || grid[r][c] != INT_MAX) {
                    continue;
                }
                grid[r][c]=grid[row][col]+1;
                q.push({r,c});
            }
        }
    }
};