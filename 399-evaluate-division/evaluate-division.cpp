class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>>adj;
        for(int i=0;i<equations.size();i++){
            string a=equations[i][0];
            string b=equations[i][1];
            adj[a].emplace_back(b, values[i]);
            adj[b].emplace_back(a, 1.0/values[i]);
        }
        vector<double>res;
        for(auto query: queries){
            string src=query[0];
            string target=query[1];
            res.push_back(bfs(src, target, adj));
        }
        return res;
    }
    double bfs(string &src, string target, unordered_map<string, vector<pair<string, double>>> &adj ){
        if(!adj.count(src)||!adj.count(target))return -1.0;
        queue<pair<string, double>>q;
        unordered_set<string>visited;
        q.emplace(src,1);
        visited.insert(src);
        while(!q.empty()){
            auto[node, weight]=q.front();
            q.pop();
            if(node==target){
                return weight;
            }
            for(auto &[nei, neiweight]:adj[node]){
                if(!visited.count(nei)){
                    visited.insert(nei);
                    q.emplace(nei,weight * neiweight);
                }
            }
        }
        return -1.0;
    }
};