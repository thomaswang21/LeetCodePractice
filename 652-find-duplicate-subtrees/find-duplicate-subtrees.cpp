/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    string solve(TreeNode *r, unordered_map<string, int> &hash, vector<TreeNode*> &ans) {
        if (r == NULL)
            return "";

        string cur = "";
        cur += to_string(r -> val) + ",";
        cur += solve(r -> left, hash, ans) + ",";
        cur += solve(r -> right, hash, ans);

        hash[cur]++;
        if (hash[cur] == 2)
            ans.push_back(r);

        return cur;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> hash;
        vector<TreeNode*> ans;

        solve(root, hash, ans);

        return ans;
    }
};

