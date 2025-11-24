
// 思路：
// 题目要求序列化和反序列化二叉树。
// 使用前序遍历（根-左-右）进行序列化，将空节点用特殊符号 "#" 表示，节点之间用逗号分隔。
// 反序列化时使用递归，根据字符串顺序依次重建二叉树。
// 时间复杂度 O(n)，空间复杂度 O(n)。

#include <string>
#include <sstream>
using namespace std;



class Codec {
public:
    // 序列化：将二叉树转为字符串
    string serialize(TreeNode* root) {
        if (!root) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // 反序列化：将字符串还原为二叉树
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }

private:
    // 辅助函数：递归构建树
    TreeNode* build(stringstream& ss) {
        string val;
        getline(ss, val, ',');
        if (val == "#" || val.empty()) return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = build(ss);
        node->right = build(ss);
        return node;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));