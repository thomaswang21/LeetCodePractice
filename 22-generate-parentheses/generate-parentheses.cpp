class Solution {
private:
    // 回溯过程中的路径
    string track = "";
    // 记录所有合法的括号组合
    vector<string> res; 
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return res;
        // 可用的左括号和右括号数量初始化为 n
        backtrack(n, n);
        return res;
    }

    // 可用的左括号数量为 left 个，可用的右括号数量为 right 个
    void backtrack(int left, int right) {
        // 若左括号剩下的多，说明不合法
        if (right < left) return;
        // 数量小于 0 肯定是不合法的
        if (left < 0 || right < 0) return;
        // 当所有括号都恰好用完时，得到一个合法的括号组合
        if (left == 0 && right == 0) {
            res.push_back(track);
            return;
        }

        // 做选择，尝试放一个左括号
        track.push_back('(');
        backtrack(left - 1, right);
        // 撤消选择
        track.pop_back();

        // 做选择，尝试放一个右括号
        track.push_back(')');
        backtrack(left, right - 1);
        // 撤销选择
        track.pop_back();
    }
};