class CBTInserter {
    // 这个队列只记录完全二叉树底部可以进行插入的节点
    private:
        queue<TreeNode*> q;
        TreeNode* root;

    public:
        CBTInserter(TreeNode* root) {
            this->root = root;
            // 进行普通的 BFS，目的是找到底部可插入的节点
            queue<TreeNode*> temp;
            temp.push(root);
            while (!temp.empty()) {
                TreeNode* cur = temp.front(); temp.pop();
                if (cur->left != nullptr) {
                    temp.push(cur->left);
                }
                if (cur->right != nullptr) {
                    temp.push(cur->right);
                }
                if (cur->right == nullptr || cur->left == nullptr) {
                    // 找到完全二叉树底部可以进行插入的节点
                    q.push(cur);
                }
            }
        }

        int insert(int val) {
            TreeNode* node = new TreeNode(val);
            TreeNode* cur = q.front();
            // 进行插入
            if (cur->left == nullptr) {
                cur->left = node;
            } else if (cur->right == nullptr) {
                cur->right = node;
                q.pop();
            }
            // 新节点的左右节点也是可以插入的
            q.push(node);
            return cur->val;
        }

        TreeNode* get_root() {
            return root;
        }
};