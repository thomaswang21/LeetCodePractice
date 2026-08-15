class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 初始化一个 n x n 的二维数组，默认全为 0
        vector<vector<int>> matrix(n, vector<int>(n));
        
        // 定义四个方向的初始边界
        int top = 0;                        // 上边界
        int bottom = n - 1;                 // 下边界
        int left = 0;                       // 左边界
        int right = n - 1;                  // 右边界
        
        int num = 1; // 用于填充的自增数字，从 1 开始直到 n * n
        
        // 只要上下边界不交错，且左右边界不交错，就继续向内收缩遍历
        while (top <= bottom && left <= right) {
            
            // 1. 贴着上边界，从左到右填充
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++; // 上边界填充完后，上边界向下收缩一行
            
            // 2. 贴着右边界，从上到下填充
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--; // 右边界填充完后，右边界向左收缩一列
            
            // 检查上下边界是否已经交错
            if (top <= bottom) {
                // 3. 贴着下边界，从右到左填充
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--; // 下边界填充完后，下边界向上收缩一行
            }
            
            // 检查左右边界是否已经交错
            if (left <= right) {
                // 4. 贴着左边界，从下到上填充
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++; // 左边界填充完后，左边界向右收缩一列
            }
        }
        
        return matrix;
    }
};