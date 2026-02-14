class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>cnt;
        for(auto c:p)cnt[c]++;
        vector<int>res;
        int tot=cnt.size();
        int satisfy=0;
        for(int i=0, j=0;i< s.size();i++){
            cnt[s[i]]--;
            if(cnt[s[i]]==0)satisfy++;
            while(i-j+1>p.size()){
                if(cnt[s[j]]==0)satisfy--;
                cnt[s[j]]++;
                j++;
            }
            if(satisfy==tot){
                res.push_back(j);
            }
        }
        return res;
    }
};