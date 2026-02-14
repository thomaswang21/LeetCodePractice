class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_set<int>temp;
        for(auto x:nums){
            temp.insert(x);
        }
        for(int i=1; i<=n;i++){
            if(!temp.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};