class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;

        while (label >= 1) {
            res.push_back(label);

            // 计算当前层
            int level = log2(label);
            int start = 1 << level;
            int end = (1 << (level + 1)) - 1;

            // 关键：先镜像，再找父节点
            label = (start + end - label) / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};



