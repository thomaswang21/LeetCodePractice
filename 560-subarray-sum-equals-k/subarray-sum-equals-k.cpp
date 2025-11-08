class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>preSum(n+1,0);
        for(int i=1; i<=n;i++){
            preSum[i]=preSum[i-1]+nums[i-1];

        }
        unordered_map<int,int>hash;
        int res=0;
        hash[0]=1;
        for(int i=1;i<=n;i++){
            res+=hash[preSum[i]-k];
            hash[preSum[i]]++;
        }
        return res;
    }
};