class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 边界条件处理
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 按照 1D 数组初始化左右边界
        int l = 0;
        int r = m * n - 1;
        
        // 使用你已经很熟悉的标准二分查找模板
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            // 将 1D 的 mid 映射回 2D 的 row 和 col
            int row = mid / n;
            int col = mid % n;
            
            int mid_val = matrix[row][col];
            
            if (mid_val == target) {
                return true; // 找到了直接返回
            } else if (mid_val < target) {
                l = mid + 1; // 目标在右半边
            } else {
                r = mid - 1; // 目标在左半边
            }
        }
        
        // 循环结束也没找到，说明不存在
        return false; 
    }
};