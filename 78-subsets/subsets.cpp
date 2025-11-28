class Solution {
public:
    vector<vector<int>>ans;
    vector<int>track;
    int n;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        n=nums.size();
        return ans;
    }
    void dfs(vector<int>&nums, int start){
        n=nums.size();
        ans.push_back(track);
        for(int i=start;i<n;i++){
            track.push_back(nums[i]);
            dfs(nums, i+1);
            track.pop_back();
        }
    }
};