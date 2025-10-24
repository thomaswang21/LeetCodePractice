class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>hash;
        for(auto t: strs){
            string nstr=t;
            sort(nstr.begin(),nstr.end());
            hash[nstr].push_back(t);
        }
        for(auto o: hash){
            ans.push_back(o.second);
        }
        return ans;
    }
};