class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // 如果深度为1，新建根节点
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // BFS 层序遍历
        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;

        while (!q.empty()) {
            int size = q.size();
            if (currentDepth == depth - 1) {
                // 到达目标层，开始插入新节点
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();

                    TreeNode* oldLeft = node->left;
                    TreeNode* oldRight = node->right;

                    node->left = new TreeNode(val);
                    node->left->left = oldLeft;

                    node->right = new TreeNode(val);
                    node->right->right = oldRight;
                }
                break;
            }

            // 否则继续向下遍历
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            currentDepth++;
        }

        return root;
    }
};
