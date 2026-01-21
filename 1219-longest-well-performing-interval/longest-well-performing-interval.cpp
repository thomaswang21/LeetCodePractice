class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        vector<int>preSum(n+1,0);
        unordered_map<int,int>hash;
        int res=0;
        for(int i=1;i<=n;i++){
            if(hours[i-1]>8){
                preSum[i]=preSum[i-1]+1;
            }else{
                preSum[i]=preSum[i-1]-1;
            }
            if(!hash.count(preSum[i])){
                hash[preSum[i]]=i;
            }
            if(preSum[i]>0){
                res=max(res, i);
            }else{
                if(hash.count(preSum[i]-1)){
                    int j=hash[preSum[i]-1];
                    res=max(res,i-j);
                }
            }
           
        }
        return res;
    }
};