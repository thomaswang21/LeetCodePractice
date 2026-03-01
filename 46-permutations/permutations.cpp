class Solution {
public:
    vector<vector<int>>ans;
    vector<int>track;
    vector<bool>used;
    vector<vector<int>> permute(vector<int>& nums) {
        used=vector<bool>(nums.size(), false);
        dfs(nums);
        return ans;
    }
    void dfs(vector<int>&nums){
        if(track.size()==nums.size()){
            ans.push_back(track);
            return;
        }
        for(int i=0; i<nums.size();i++){
            if(used[i])continue;
            track.push_back(nums[i]);
            used[i]=true;
            dfs(nums);
            track.pop_back();
            used[i]=false;
        }
    }
};