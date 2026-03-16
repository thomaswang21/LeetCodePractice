

class CBTInserter {
private:
    TreeNode* root; // 根节点
    queue<TreeNode*> q; // 队列用于存储未满的节点

public:
    // 构造函数，初始化时进行层序遍历，找到所有未满的节点
    CBTInserter(TreeNode* root) {
        this->root = root; // 保存根节点
        queue<TreeNode*> tmp; // 临时队列用于层序遍历
        tmp.push(root); // 根节点入队
        while (!tmp.empty()) {
            TreeNode* node = tmp.front(); // 取队首节点
            tmp.pop(); // 出队
            // 如果该节点的左右孩子不全，则加入q队列
            if (!(node->left && node->right)) {
                q.push(node);
            }
            // 左右孩子入队继续遍历
            if (node->left) tmp.push(node->left);
            if (node->right) tmp.push(node->right);
        }
    }

    // 插入新节点
    int insert(int val) {
        TreeNode* node = new TreeNode(val); // 创建新节点
        TreeNode* parent = q.front(); // 队首节点为父节点
        // 如果父节点没有左孩子，则插入左边
        if (!parent->left) {
            parent->left = node;
        } 
        // 否则插入右边，并弹出该父节点
        else {
            parent->right = node;
            q.pop();
        }
        // 新节点也可能成为未来的父节点，入队
        q.push(node);
        // 返回父节点的值
        return parent->val;
    }

    // 返回根节点
    TreeNode* get_root() {
        return root;
    }
};
