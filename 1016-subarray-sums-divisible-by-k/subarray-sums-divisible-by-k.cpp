class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>preSum(n+1,0);
        unordered_map<int, int>hash;
        int res=0;
        for(int i=1;i<=n;i++)preSum[i]=preSum[i-1]+nums[i-1];
        hash[0]=1;
        for(int i=1;i<=n;i++){
            int cur=preSum[i]%k;
            if(cur<0){
                cur+=k;
            }
            if(hash.find(cur)!=hash.end()){
                res+=hash[cur];
            }
            hash[cur]++;
        }
        return res;
    }
};