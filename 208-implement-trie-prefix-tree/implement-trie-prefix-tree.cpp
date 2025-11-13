
// 思路：使用 Trie（前缀树）实现字符串的插入、查找和前缀匹配
// 每个节点包含 26 个子节点指针（对应 'a' 到 'z'）和一个标志位表示是否是单词结尾
// insert：逐字符创建节点
// search：逐字符查找，最后检查是否是单词结尾
// startsWith：逐字符查找前缀是否存在

#include <string>
using namespace std;

class Trie {
private:
    // 定义 Trie 节点结构
    struct TrieNode {
        TrieNode* children[26]; // 子节点数组
        bool isEnd; // 是否为单词结尾

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

    TrieNode* root; // 根节点

public:
    Trie() {
        root = new TrieNode(); // 初始化根节点
    }

    // 插入单词
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true; // 标记单词结尾
    }

    // 查找完整单词
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd; // 只有到达结尾并且标记为单词结尾才返回 true
    }

    // 查找前缀
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return true; // 只要能遍历完前缀就返回 true
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */