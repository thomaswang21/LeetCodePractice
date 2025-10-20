class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int left=0, right=m*n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(get(matrix, mid)==target){
                return true;
            }else if(get(matrix,mid)<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return false;
    }
    int get(vector<vector<int>>&matrix, int index){
        int m=matrix.size(), n=matrix[0].size();
        int i=index/n, j=index%n;
        return matrix[i][j];
    }
};