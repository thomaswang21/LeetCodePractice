class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        vector<int> res(nums1.size());
        priority_queue<pair<int,int>>pq;
        for(int i =0; i < nums2.size(); i++){
            pq.push({nums2[i],i});
        }
        int left = 0, right = nums1.size()-1;
        while(!pq.empty()){
            auto pair = pq.top();
            pq.pop();
            int i = pair. second, max = pair.first;
            if(max < nums1[right]){
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