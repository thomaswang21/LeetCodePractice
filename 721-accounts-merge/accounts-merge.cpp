class Solution {
private:
    class UF {
    public:
        vector<int> parent;
        vector<int> size;

        UF(int n) {
            parent = vector<int>(n);
            size = vector<int>(n, 1);
            for (int i = 0; i < n; ++i) parent[i] = i;
        }

        int find(int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        void unionNodes(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ) return;

            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;
        int id = 0;

        // 1️⃣ 给每个 email 编号
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                if (!emailToId.count(acc[i])) {
                    emailToId[acc[i]] = id++;
                    emailToName[acc[i]] = name;
                }
            }
        }

        // 2️⃣ 初始化并查集
        UF uf(id);

        // 3️⃣ 合并同一账户下的 email
        for (auto& acc : accounts) {
            int firstEmailId = emailToId[acc[1]];
            for (int i = 2; i < acc.size(); i++) {
                uf.unionNodes(firstEmailId, emailToId[acc[i]]);
            }
        }

        // 4️⃣ 按 root 分组
        unordered_map<int, vector<string>> groups;
        for (auto& p : emailToId) {
            int root = uf.find(p.second);
            groups[root].push_back(p.first);
        }

        // 5️⃣ 构建结果
        vector<vector<string>> res;
        for (auto& g : groups) {
            auto& emails = g.second;
            sort(emails.begin(), emails.end());

            vector<string> cur;
            cur.push_back(emailToName[emails[0]]);
            cur.insert(cur.end(), emails.begin(), emails.end());

            res.push_back(cur);
        }

        return res;
    }
};

