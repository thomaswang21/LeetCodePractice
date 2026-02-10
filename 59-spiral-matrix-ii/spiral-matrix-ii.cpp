#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Initialize an n x n matrix with zeros
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        
        while (num <= n * n) {
            // 1. Fill Right: across the top row
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++;
            
            // 2. Fill Down: down the right column
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--;
            
            // 3. Fill Left: across the bottom row
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
            
            // 4. Fill Up: up the left column
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
        
        return matrix;
    }
};