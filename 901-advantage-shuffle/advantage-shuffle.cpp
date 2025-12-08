class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>>maxpq;
        for(int i=0; i<n;i++){
            maxpq.push({nums2[i],i});
        }
        sort(nums1.begin(),nums1.end());
        int left=0, right=nums2.size()-1;
        vector<int>res(n);
        while(!maxpq.empty()){
            auto pair=maxpq.top();
            maxpq.pop();
            int i=pair.second, maxval=pair.first;
            if(maxval<nums1[right]){
                res[i]=nums1[right];
                right--;
            }else{
                res[i]=nums1[left];
                left++;
            }
        }
        return res;
    }
};