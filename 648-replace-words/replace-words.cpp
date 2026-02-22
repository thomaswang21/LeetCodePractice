#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
private:
    // Trie节点定义
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root;

    // 插入根词
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;
    }

    // 查找单词的最短根
    string searchRoot(const string& word) {
        TrieNode* node = root;
        string prefix = "";
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) break; // 没有匹配
            prefix += c;
            node = node->children[index];
            if (node->isEnd) return prefix; // 找到最短根
        }
        return word; // 没有根，返回原单词
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();

        // 1. 插入所有根词
        for (const string& word : dictionary) {
            insert(word);
        }

        // 2. 分词处理句子
        istringstream iss(sentence);
        string word;
        string result = "";
        while (iss >> word) {
            string rootWord = searchRoot(word); // 查找最短根
            if (!result.empty()) result += " ";
            result += rootWord;
        }

        return result;
    }
};
