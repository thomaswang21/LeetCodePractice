class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        return countPseudoPalindromicPaths(root, 0);
    }

private:
    int countPseudoPalindromicPaths(TreeNode* node, int path) {
        if (!node) {
            return 0;
        }

        // 用位运算记录当前路径每个数字的奇偶次数
        path ^= (1 << node->val);

        // 到达叶子节点
        if (!node->left && !node->right) {
            // 判断是否为伪回文路径
            if ((path & (path - 1)) == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        int leftCount = countPseudoPalindromicPaths(node->left, path);
        int rightCount = countPseudoPalindromicPaths(node->right, path);
        return leftCount + rightCount;
    }
};
