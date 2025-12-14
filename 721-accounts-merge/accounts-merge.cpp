
// 思路说明：
// 题目要求合并账户：如果两个账户有相同的邮箱，则它们属于同一个人。
// 我们可以使用并查集（Union-Find）来实现邮箱的合并。
// 1. 每个邮箱视为一个节点。
// 2. 对于同一个账户中的所有邮箱，将它们合并到同一个集合中。
// 3. 用哈希表记录邮箱对应的用户名。
// 4. 合并完成后，按集合分组邮箱，并排序输出。

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 并查集结构
class UnionFind {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    void unite(string a, string b) {
        string pa = find(a);
        string pb = find(b);
        if (pa != pb) {
            parent[pb] = pa;
        }
    }

    void add(string x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf;
        unordered_map<string, string> emailToName;

        // 初始化并查集并建立邮箱与用户名映射
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                uf.add(acc[i]);
                emailToName[acc[i]] = name;
                if (i > 1) {
                    uf.unite(acc[1], acc[i]); // 合并同一账户的邮箱
                }
            }
        }

        // 按根节点分组邮箱
        unordered_map<string, vector<string>> groups;
        for (auto& p : emailToName) {
            string root = uf.find(p.first);
            groups[root].push_back(p.first);
        }

        // 构建结果
        vector<vector<string>> result;
        for (auto& g : groups) {
            vector<string> emails = g.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[g.first]);
            result.push_back(emails);
        }

        return result;
    }
};
