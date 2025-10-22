/*

    Time Complexity : O((N*M)*(N+M)), Where N is the number of row and M is number of column of matrix. Here
    nested loops creates the time complexity. O(N*M) for traversing through each element and (N+M) for traversing
    to row and column of elements having value 0.

    Space Complexity : O(N*M), visited matrix space.

    Solved using Matrix with Extra space.

*/


/***************************************** Approach 1 Code *****************************************/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();         // 行数
        int m = matrix[0].size();      // 列数

        vector<vector<int>> visited = matrix;  // 拷贝一份原矩阵

        // 第一次遍历：把含 0 元素所在行在 visited 里置为 0
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){
                        visited[i][k] = 0;
                    }
                }
            }
        }

        // 第二次遍历：把含 0 元素所在列在 visited 里置为 0
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<n; k++){
                        visited[k][j] = 0;
                    }
                }
            }
        }

        // 把 visited 里的内容复制回原始 matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = visited[i][j];
            }
        }
    }
};






