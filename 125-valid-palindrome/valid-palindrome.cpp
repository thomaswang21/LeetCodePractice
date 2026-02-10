class Solution {
public:
    bool isPalindrome(string s) {
        string sb="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isalnum(c)){
                sb+=tolower(c);
            }
        }
        s=sb;
        int left=0, right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }
        return true;
    }
};