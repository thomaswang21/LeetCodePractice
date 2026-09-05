class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Initialize the prefix matrix with dimensions (m+1) x (n+1) filled with 0s
        prefix.assign(m + 1, vector<int>(n + 1, 0));
        
        // Build the 2D prefix sum array
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix[i][j] = matrix[i - 1][j - 1] 
                             + prefix[i - 1][j] 
                             + prefix[i][j - 1] 
                             - prefix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // row2 and col2 are shifted by +1 to map to our 1-based prefix array
        // row1 and col1 remain unchanged to naturally subtract the elements BEFORE the boundary
        return prefix[row2 + 1][col2 + 1] 
             - prefix[row1][col2 + 1] 
             - prefix[row2 + 1][col1] 
             + prefix[row1][col1];
    }
};