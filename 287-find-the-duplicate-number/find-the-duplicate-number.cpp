class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>hash;
        for(auto a:nums){
            if(hash.count(a)){
            return a;
        }
        hash.insert(a);
        }
        return -1;
    }
};