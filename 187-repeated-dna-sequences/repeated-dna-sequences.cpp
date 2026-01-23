class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        unordered_set<string>seen;
        unordered_set<string>dup;
        for(int i=0; i+10<=n;i++){
            string seq=s.substr(i,10);
            if(seen.count(seq)){
                dup.insert(seq);
            }
            seen.insert(seq);
        }
        return vector<string>(dup.begin(),dup.end());
    }
};