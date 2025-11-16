class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>hash;
        for(auto a:nums){
            if(hash.count(a)){
                return true;
            }
        else{
            hash.insert(a);
        }
    }
    return false;
    }
};