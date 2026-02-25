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
    vector<int> a, b;
    unordered_map<int, int> pos;

    TreeNode* build(int x, int y, int l, int r) {
        if (x > y) return NULL;
        auto root = new TreeNode(a[x]);
        int k = pos[root->val];
        root->left = build(x + 1, k - l + x, l, k - 1);
        root->right = build(k - l + x + 1, y, k + 1, r);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        a = b = preorder;
        int n = a.size();
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i ++ ) pos[b[i]] = i;
        return build(0, n - 1, 0, n - 1);
    }
};

