// 一个生成二叉树叶子节点的迭代器
class LeafIterator {
    // 模拟递归过程
    stack<TreeNode*> stk;

public:
    LeafIterator(TreeNode* root) {
        if (root != nullptr) {
            stk.push(root);
        }
    }

    bool hasNext() {
        return !stk.empty();
    }

    TreeNode* next() {
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur->left == nullptr && cur->right == nullptr) {
                // 发现一个叶子结点
                return cur;
            }
            // 先入栈 root.right
            if (cur->right != nullptr) {
                stk.push(cur->right);
            }
            if (cur->left != nullptr) {
                stk.push(cur->left);
            }
        }
        return nullptr;
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        LeafIterator it1(root1);
        LeafIterator it2(root2);
        // 逐一对比叶子节点
        while (it1.hasNext() && it2.hasNext()) {
            if (it1.next()->val != it2.next()->val) {
                return false;
            }
        }
        // 最后应该都完成遍历
        return !it1.hasNext() && !it2.hasNext();
    }
};