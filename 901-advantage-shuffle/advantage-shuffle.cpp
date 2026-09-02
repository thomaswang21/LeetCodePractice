class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        priority_queue<pair<int,int>>pq;
        for(int i =0; i < n; i++){
            pq.push({nums2[i], i});
        }

        sort(nums1.begin(), nums1.end());
        int left = 0, right = nums2.size()-1;
        vector<int> res(n);
        while(!pq.empty()){
            auto pair = pq.top();
            pq.pop();
            int i = pair.second , max = pair.first;
            if(max<nums1[right]){
                res[i] = nums1[right];
                right--;
            }else{
                res[i] = nums1[left];
                left++;
            }
        }
        return res;
    }
};