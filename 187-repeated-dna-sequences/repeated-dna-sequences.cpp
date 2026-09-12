class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10) return {};
        unordered_set<string> seen;
        unordered_set<string> repeated;

        for(int i = 0; i <= s.length() -10; i++){
            string current = s.substr(i, 10);
            if(seen.count(current)){
                repeated.insert(current);
            }else{
                seen.insert(current);
            }
        }
        return vector<string>(repeated.begin(), repeated.end());
    }
};