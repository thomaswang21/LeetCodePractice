class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,int>> pg;
        for (int i = 0; i < p.size(); i++) {
            int dist = p[i][0] * p[i][0] + p[i][1] * p[i][1];
            pg.push({-dist, i});
        }

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {  // 用 for 循环替代 while
            auto x = pg.top();
            pg.pop();
            ans.push_back(p[x.second]);
        }

        return ans;
    }
};
