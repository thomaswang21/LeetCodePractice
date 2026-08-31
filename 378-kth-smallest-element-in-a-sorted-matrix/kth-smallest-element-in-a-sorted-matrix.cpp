class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n =matrix.size();
        int m =matrix[0].size();
        priority_queue<int> heap;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                heap.push(matrix[i][j]);
                if(heap.size() > k) heap.pop();
            }
        }
        return heap.top();
    }
};