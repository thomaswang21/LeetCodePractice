class Solution {
public:
    vector<TreeNode*> ans;
    unordered_set<int> hash;

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto val: to_delete) hash.insert(val);
        dfs(root, false);
        return ans;
    }

    void dfs(TreeNode*& root, bool has_father) {
        if (hash.count(root->val)) {
            if (root->left) dfs(root->left, false);
            if (root->right) dfs(root->right, false);
            root = nullptr;
        } else {
            if (!has_father) ans.push_back(root);
            if (root->left) dfs(root->left, true);
            if (root->right) dfs(root->right, true);
        }
    }
};

