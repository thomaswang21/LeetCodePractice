class Solution {
public:
    vector<int>track;
    vector<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        
        return ans;
    }
    void dfs(vector<int>&nums, int start){
        ans.push_back(track);
        for(int i=start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1])continue;
            track.push_back(nums[i]);
            dfs(nums, i+1);
            track.pop_back();
        }
    }
};