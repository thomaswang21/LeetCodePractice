class Solution {
public:
    vector<int>track;
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,0,target,0);
        return res;
    }
    void backtrack(vector<int>&nums, int start, int target, int sum ){
        if(sum==target){
            res.push_back(track);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=start;i<nums.size();i++){
            track.push_back(nums[i]);
            sum+=nums[i];
            backtrack(nums, i,target,sum);
            sum-=nums[i];
             track.pop_back();
        }
    }
};