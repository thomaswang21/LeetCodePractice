class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Check if reshape is possible and legal
        if (m * n != r * c) {
            return mat;
        }
        
        vector<vector<int>> reshaped(r, vector<int>(c));
        
        // Map 2D array to 1D and back to the new 2D array
        for (int i = 0; i < m * n; ++i) {
            reshaped[i / c][i % c] = mat[i / n][i % n];
        }
        
        return reshaped;
    }
};