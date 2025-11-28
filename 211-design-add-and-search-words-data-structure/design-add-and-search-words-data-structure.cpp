
// 思路：使用字典树（Trie）实现单词添加与搜索
// 每个节点包含26个子节点指针和一个标记是否为单词结尾的布尔值
// addWord函数逐字符插入
// search函数支持'.'通配符，用DFS递归匹配所有可能路径

#include <string>
#include <vector>
using namespace std;

// 定义Trie节点结构
struct TrieNode {
    TrieNode* children[26]; // 子节点
    bool isEnd; // 是否为单词结尾
    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root; // 根节点

    // 辅助DFS函数，用于处理'.'通配符
    bool dfs(TrieNode* node, const string& word, int index) {
        if (index == word.size()) return node->isEnd;
        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && dfs(node->children[i], word, index + 1))
                    return true;
            }
            return false;
        } else {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            return dfs(node->children[idx], word, index + 1);
        }
    }

public:
    // 构造函数，初始化根节点
    WordDictionary() {
        root = new TrieNode();
    }

    // 添加单词到字典树
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // 搜索单词，支持'.'匹配任意字母
    bool search(string word) {
        return dfs(root, word, 0);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */