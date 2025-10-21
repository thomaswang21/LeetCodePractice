class Solution {
public:
    int rows;
    int cols;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        rows=grid.size();
        cols=grid[0].size();
        for(int i=0; i<rows;i++){
            for(int j=0;j<cols; j++){
                if(grid[i][j]==1){
                    area=max(area, dfs(grid, i,j));
                }
            }
            
        }
        return area;
    }
    int dfs(vector<vector<int>>&grid, int i, int j){
        if(i<0||i>=rows||j<0||j>=cols||grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        int res=1;
        res+=dfs(grid, i+1, j);
            res+=dfs(grid, i, j+1);
            res+=dfs(grid, i-1, j);
            res+=dfs(grid, i, j-1);
            return res;
    }
};