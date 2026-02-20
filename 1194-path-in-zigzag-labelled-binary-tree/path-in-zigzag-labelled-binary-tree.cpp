class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        while (label) res.push_back(label), label >>= 1;

        reverse(res.begin(), res.end());

        for (int i = res.size() % 2; i < res.size(); i += 2) {
            res[i] ^= ((1 << i) - 1);
        }

        return res;
    }
};

