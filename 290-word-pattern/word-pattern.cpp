class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream raw(str);
        vector<string>strs;
        string line;
        while(raw>>line)strs.push_back(line);
        unordered_map<char, string>PS;
        unordered_map<string, char>SP;
        if(pattern.size()!=strs.size())return false;
        for(int i=0; i<pattern.size();i++){
            if(!PS.count(pattern[i]))PS[pattern[i]]=strs[i];
            if(!SP.count(strs[i]))SP[strs[i]]=pattern[i];
            if(PS[pattern[i]]!=strs[i])return false;
            if(SP[strs[i]]!=pattern[i])return false;
        }
        return true;
    }
};