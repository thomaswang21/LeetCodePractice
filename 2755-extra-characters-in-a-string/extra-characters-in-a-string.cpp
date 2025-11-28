#include <bits/stdc++.h>
using namespace std;

// Trie 节点定义
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for(int i=0;i<26;i++) children[i] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;
    unordered_map<int,int> memo; // 记忆化 DFS

    // DFS 函数返回从 index 开始的最少额外字符数
    int dfs(const string& s, int index) {
        if (index == s.size()) return 0; // 到末尾没有额外字符
        if (memo.count(index)) return memo[index];

        int res = 1 + dfs(s, index + 1); // 默认 s[index] 是额外字符

        TrieNode* node = root;
        for (int i = index; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (!node->children[c]) break;
            node = node->children[c];
            if (node->isEnd) {
                res = min(res, dfs(s, i + 1)); // 子串匹配字典单词，不增加额外字符
            }
        }

        return memo[index] = res;
    }

public:
    // 构造 Trie
    Solution() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        // 构建 Trie
        for (const string& word : dictionary) insert(word);
        memo.clear();
        return dfs(s, 0);
    }
};
