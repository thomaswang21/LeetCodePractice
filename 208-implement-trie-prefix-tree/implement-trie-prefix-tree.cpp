class TrieNode {
public:
    TrieNode* children[26]; // 子节点指针数组
    bool isEnd; // 是否为单词结尾

    TrieNode() {
        for( int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    // 构造函数 O(1)
    Trie() {
        root = new TrieNode();
    }

    // 插入单词 O(L)
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // 查找完整单词 O(L)
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    // 查找前缀 O(L)
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) return false;
            node = node->children[idx];
        }
        return true;
    }
};
