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

    unordered_map<int,int> pos;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i ++ )
            pos[inorder[i]] = i;
        return dfs(postorder, inorder, 0, n - 1, 0, n - 1);
    }

    // pl, pr 表示当前子树后序遍历在数组中的位置
    // il, ir 表示当前子树中序遍历在数组中的位置
    TreeNode* dfs(vector<int>&post, vector<int>&in, int pl, int pr, int il, int ir)
    {
        if (pl > pr) return NULL;
        int k = pos[post[pr]] - il;
        TreeNode* root = new TreeNode(post[pr]);
        root->left = dfs(post, in, pl, pl + k - 1, il, il + k - 1);
        root->right = dfs(post, in, pl + k, pr - 1, il + k + 1, ir);
        return root;
    }
};

