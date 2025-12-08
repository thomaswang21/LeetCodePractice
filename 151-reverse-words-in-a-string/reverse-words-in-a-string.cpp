class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n=s.length();
        string ans="";
        string word="";
        for(int i=0; i<n;i++){
            if(s[i]!=' '){
                word+=s[i];
            }else if(!word.empty()){
                reverse(word.begin(), word.end());
                if(!ans.empty()){
                    ans+=" ";
                }
                ans+=word;
                word="";
            }
        }
        if(!word.empty()){
            reverse(word.begin(), word.end());
            if(!ans.empty()){
                ans+=" ";
            }
            ans+=word;
        }
        return ans;
    }
};