

class Solution {
public:
    int leftCount;   // x的左子树节点数
    int rightCount;  // x的右子树节点数

    // DFS统计节点数
    int countNodes(TreeNode* node, int x) {
        if (!node) return 0;
        int left = countNodes(node->left, x);
        int right = countNodes(node->right, x);
        if (node->val == x) {
            leftCount = left;
            rightCount = right;
        }
        return left + right + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        leftCount = 0;
        rightCount = 0;
        countNodes(root, x);
        int parentSide = n - leftCount - rightCount - 1; // 父节点方向的节点数
        int maxPart = max(leftCount, max(rightCount, parentSide));
        return maxPart > n / 2;
    }
};

