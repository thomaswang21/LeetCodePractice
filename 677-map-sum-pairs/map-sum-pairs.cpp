

// Trie节点定义
struct TrieNode {
    unordered_map<char, TrieNode*> children; // 子节点
    int sum; // 当前前缀下的总和
    TrieNode() { sum = 0; }
};

class MapSum {
private:
    TrieNode* root; // 根节点
    unordered_map<string, int> mp; // 存储key对应的值，方便计算差值

public:
    // 构造函数 O(1)
    MapSum() {
        root = new TrieNode();
    }

    // 插入函数 O(L)
    void insert(string key, int val) {
        int diff = val;
        if (mp.find(key) != mp.end()) {
            diff = val - mp[key]; // 计算差值
        }
        mp[key] = val; // 更新哈希表

        TrieNode* node = root;
        for (char c : key) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->sum += diff; // 更新路径上的sum
        }
    }

    // 前缀求和 O(L)
    int sum(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) return 0;
            node = node->children[c];
        }
        return node->sum;
    }
};

