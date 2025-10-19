class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>hash;
        for(auto str: strs){
            string nstr=str;
            sort(nstr.begin(), nstr.end());
            hash[nstr].push_back(str);
        }
        for(auto item:hash){
            res.push_back(item.second);
        }
        return res;
        
    }
};