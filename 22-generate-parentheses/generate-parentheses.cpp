class Solution {
public:
    vector<string>ans;

    vector<string> generateParenthesis(int n) {
        dfs(n,0,0,"");
        return ans;    
    }
    void dfs(int n, int lc, int rc, string sec){
        if(lc==n&&rc==n){
            ans.push_back(sec);
            return;
        }
        if(lc<n){
            dfs(n, lc+1, rc,sec+'(');
        }
        if(rc<n&&rc<lc){
            dfs(n, lc, rc+1, sec+')');
        }
    }
};