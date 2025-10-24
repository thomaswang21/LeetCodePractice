class Solution {
public:
    vector<int>track;
    vector<vector<int>>res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int>&nums, int start){
        res.push_back(track);
        for(int i=start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1])continue;
            track.push_back(nums[i]);
            backtrack(nums, i+1);
            track.pop_back();
        }
    }
};