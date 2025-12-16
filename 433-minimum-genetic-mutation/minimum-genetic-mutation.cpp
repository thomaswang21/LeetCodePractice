class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end()) {
            return -1;
        }
        vector<char> AGCT = {'A', 'G', 'C', 'T'};

        // BFS 标准框架
        queue<string> q;
        unordered_set<string> visited;
        q.push(startGene);
        visited.insert(startGene);
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            
            for (int j = 0; j < sz; j++) {
                string cur = q.front();
                q.pop();
                if (cur == endGene) {
                    return step;
                }
                // 向周围扩散
                for (const string& newGene : getAllMutation(cur)) {
                    if (visited.find(newGene) == visited.end() && bankSet.find(newGene) != bankSet.end()) {
                        q.push(newGene);
                        visited.insert(newGene);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    // 当前基因的每个位置都可以变异为 A/G/C/T，穷举所有可能的结构
    vector<string> getAllMutation(const string& gene) {
        vector<string> res;
        string geneChars = gene;
        for (int i = 0; i < geneChars.length(); i++) {
            char oldChar = geneChars[i];
            for (char newChar : vector<char>{'A', 'G', 'C', 'T'}) {
                geneChars[i] = newChar;
                res.push_back(geneChars);
            }
            geneChars[i] = oldChar;
        }
        return res;
    }
};