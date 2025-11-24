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
vector<int> vc;
void inorder(TreeNode *root) {
    if (root == nullptr) return;
    inorder(root -> left);
    vc.emplace_back(root -> val);
    inorder(root -> right);
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vc.clear();
        inorder(root);
        for (int i = 0; i < (int)vc.size() - 1; i++) {
            if (vc[i] >= vc[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
