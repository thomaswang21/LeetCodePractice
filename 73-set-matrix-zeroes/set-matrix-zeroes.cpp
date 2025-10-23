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
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){
                        visited[i][k] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<n; k++){
                        visited[k][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = visited[i][j];
            }
        }
    }
};






