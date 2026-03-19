
using namespace std;

// Trie节点定义
struct TrieNode {
    unordered_map<char, TrieNode*> children; // 子节点
    int wordCount; // 当前节点结尾的单词数
    int prefixCount; // 当前节点作为前缀的单词数
    TrieNode() {
        wordCount = 0;
        prefixCount = 0;
    }
};

class Trie {
private:
    TrieNode* root; // 根节点

public:
    // 构造函数 O(1)
    Trie() {
        root = new TrieNode();
    }

    // 插入单词 O(L)
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->prefixCount++; // 前缀计数+1
        }
        node->wordCount++; // 单词结尾计数+1
    }

    // 统计单词出现次数 O(L)
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) return 0;
            node = node->children[c];
        }
        return node->wordCount;
    }

    // 统计以prefix为前缀的单词数 O(L)
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) return 0;
            node = node->children[c];
        }
        return node->prefixCount;
    }

    // 删除单词 O(L)
    void erase(string word) {
        if (countWordsEqualTo(word) == 0) return; // 若不存在则不删
        TrieNode* node = root;
        for (char c : word) {
            TrieNode* next = node->children[c];
            next->prefixCount--; // 前缀计数-1
            node = next;
        }
        node->wordCount--; // 单词结尾计数-1
    }
};

