class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int total=n*m;
            vector<vector<int>> ans(n, vector<int>(m)); // 初始化结果网格

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int index=i*m+j;
                int newIndex=(index+k)%total;
                int newI=newIndex/m;
                int newJ=newIndex%m;
                ans[newI][newJ]=grid[i][j];
            }
        }
        return ans;
    }
};