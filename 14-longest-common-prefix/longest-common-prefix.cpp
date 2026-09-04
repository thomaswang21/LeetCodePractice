class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string start = strs[0];
        int n = strs.size() - 1;
        string last = strs[n];
        string s= "";
        for(int i = 0; i < start.size(); i++){
            if(start[i] == last[i]){
                s += start[i];
            }else{
                break;
            }
        }
        return s;
    }
};