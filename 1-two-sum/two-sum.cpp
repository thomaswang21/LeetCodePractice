class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int num=target-nums[i];
            if(hash.count(num)&&hash[num]!=i)return {i,hash[num]};
        }
        return{};
    }
};