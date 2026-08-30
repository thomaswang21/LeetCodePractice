class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int n1 = nums1.size();
        int n2 = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>minHeap;
        for(int i = 0; i < n1 && i<k; i++){
            minHeap.push({nums1[i] + nums2[0], i , 0});
        }
        while(k>0 && !minHeap.empty()){
            vector<int> top = minHeap.top();
            minHeap.pop();
            int i = top[1];
            int j = top[2];
            result.push_back({nums1[i], nums2[j]});
            k--;

            if(j + 1 < n2){
                minHeap.push({nums1[i]+nums2[j+1], i, j+1});
            }
        }
        return result;
    }
};