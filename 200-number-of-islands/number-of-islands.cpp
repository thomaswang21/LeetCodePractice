class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int row=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid, i,j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>&grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n){
            return;
        }
       if (grid[i][j]=='0')return;
        grid[i][j]='0';
        dfs(grid, i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);

    }
};