#include <vector>

class Solution {

    std::vector<int> res;

public:
    std::vector<int> lexicalOrder(int n) {
        // 总共有 9 棵多叉树，从 1 开始
        for (int i = 1; i < 10; i++) {
            traverse(i, n);
        }
        return res;
    }

    // 多叉树遍历框架，前序位置收集所有小于 n 的节点
    void traverse(int root, int n) {
        if (root > n) {
            return;
        }
        res.push_back(root);

        for (int child = root * 10; child < root * 10 + 10; child++) {
            traverse(child, n);
        }
    }
};