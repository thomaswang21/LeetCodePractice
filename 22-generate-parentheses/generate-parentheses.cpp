class Solution {
private:
    string track="";
    vector<string>res;
public:
    vector<string> generateParenthesis(int n) {
        if(n==0)return res;
        backtrack(n,n);
        return res;
    }
    void backtrack(int left, int right){
        if(right<left)return;
        if(left<0||right<0)return;
        if(left==0&&right==0){
            res.push_back(track);
            return;
        }
        track.push_back('(');
        backtrack(left-1,right);
        track.pop_back();
        track.push_back(')');
        backtrack(left, right-1);
        track.pop_back();
    }
};