class Solution {
public:
    bool ans = true;
    bool isValidSerialization(string preorder) {
        preorder += ',';
        int u = 0;
        dfs(preorder, u);
        return ans && u == preorder.size();
    }

    void dfs(string &preorder, int &u)
    {
        if (u == preorder.size())
        {
            ans = false;
            return;
        }
        if (preorder[u] == '#')
        {
            u += 2;
            return;
        }
        while (preorder[u] != ',') u ++ ; u ++ ;
        dfs(preorder, u);
        dfs(preorder, u);
    }
};

