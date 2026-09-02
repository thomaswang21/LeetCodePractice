class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n=strs.size();
        string a=strs[0] , b=strs[n-1];
        string str;
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])str+=a[i];
            else break;
        }
        return str;
    }
};