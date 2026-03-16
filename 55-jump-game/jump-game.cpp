class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int farthest=0;
        int i;
        for(i=0; i<n-1;i++){
            farthest=max(farthest, i+nums[i]);
            if(farthest==i)return false;
        }
        return farthest>=n-1;
    }
};