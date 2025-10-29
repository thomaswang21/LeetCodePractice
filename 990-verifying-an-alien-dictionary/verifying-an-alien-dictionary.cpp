class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>p;
        for(int i=0;i<order.size();i++){
            p[order[i]]=i;
        }
        for(int i=1;i<words.size();i++){
            string &a=words[i-1];
            string &b=words[i];
            int j=0;
            while(j<a.size()&&j<b.size()){
                if(p[a[j]]>p[b[j]])return false;
                if(p[a[j]]<p[b[j]])break;
                j++;
            }
            if(j==b.size()&&j<a.size())return false;
        }
        return true;
    }
};