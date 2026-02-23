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
public:
    unordered_map<int, int> hash;
    vector<int> ans;
    int maxc = 0;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int sum = root->val + dfs(root->left) + dfs(root->right);
        hash[sum] ++ ;
        if (hash[sum] > maxc) {
            maxc = hash[sum];
            ans = {sum};
        } else if (hash[sum] == maxc) {
            ans.push_back(sum);
        }
        return sum;
    }
};

