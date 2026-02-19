class Solution {
public:
    vector<int> ans;

    bool dfs(TreeNode* root, vector<int>& voyage, int& k) {
        if (!root) return true;
        if (root->val != voyage[k]) return false;
        k ++ ;
        if (root->left && root->left->val != voyage[k]) {
            ans.push_back(root->val);
            return dfs(root->right, voyage, k) && dfs(root->left, voyage, k);
        } else {
            return dfs(root->left, voyage, k) && dfs(root->right, voyage, k);
        }
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int k = 0;
        if (dfs(root, voyage, k)) return ans;
        return {-1};
    }
};

