class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>>diagonals;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                diagonals[i-j].push(mat[i][j]);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mat[i][j]=diagonals[i-j].top();
                diagonals[i-j].pop();
            }
        }
        return mat;
    }
};