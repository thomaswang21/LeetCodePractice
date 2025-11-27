class Solution {
public:
    vector<string> ans;
    string track;

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return ans;
    }

    void dfs(int n, int left, int right) {
        // left：当前使用了多少 '('
        // right：当前使用了多少 ')'

        // 1. 如果左右都用满 n 个，加入答案
        if (left == n && right == n) {
            ans.push_back(track);
            return;
        }

        // 2. 选择 '('
        if (left < n) {
            track.push_back('(');
            dfs(n, left + 1, right);
            track.pop_back();
        }

        // 3. 选择 ')'
        //   前提：右括号不能超过左括号
        if (right < left) {
            track.push_back(')');
            dfs(n, left , right+1);
            track.pop_back();
        }
    }
};
