class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int end=0;
        int farthest=0;
        int jumps=0;
        for(int i=0; i<nums.size()-1;i++){
            farthest=max(farthest, nums[i]+i);
            if(i==end){
                jumps++;
                end=farthest;
                if(end>=n-1){
                    break;
                }
            }
        }
        return jumps;
    }
};