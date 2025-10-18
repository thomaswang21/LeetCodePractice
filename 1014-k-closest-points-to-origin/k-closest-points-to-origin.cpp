class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,int>>pg;
        for(int i=0; i<p.size();i++){
            int dist=p[i][0]*p[i][0]+p[i][1]*p[i][1];
            pg.push({-1*dist, i});
        }
        vector<vector<int>>ans;
        while(k--){
            auto x=pg.top();
            pg.pop();
            ans.push_back(p[x.second]);
        }
        return ans;
    }
};