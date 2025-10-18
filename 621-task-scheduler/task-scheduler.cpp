class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans=0;
        unordered_map<char,int>mp;
        priority_queue<int>q;
        for(auto i: tasks){
            mp[i]++;
        }
        for(auto j:mp){
            q.push(j.second);
        }
        while(!q.empty()){
            int tt=0;
            vector<int>v;
            for(int i=0; i<=n;i++){
                if(!q.empty()){
                    v.push_back(q.top()-1);
                    q.pop();
                    tt=tt+1;
                }
            }
            for(auto i:v){
                if(i>0)
                q.push(i);
            }
            if(q.empty()){
                ans+=tt;
            }else {
                ans+=(n+1);
            }
        }
        return ans;
    }
};