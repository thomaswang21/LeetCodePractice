class Solution {
public:
    vector<TreeNode*> res;

    void recoverTree(TreeNode* root) {
        dfs(root);
        for (int i = 0; i < res.size(); i ++)
            for (int j = i + 1; j < res.size(); j ++)
                if (res[i]->val > res[j]->val)
                    swap(res[i]->val, res[j]->val);
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        res.push_back(root);
        dfs(root->right);
    }
};




