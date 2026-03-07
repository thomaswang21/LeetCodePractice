

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int level = 0;
        int temp = label;
        // 计算label所在层数
        while (temp > 0) {
            temp /= 2;
            level++;
        }
        // 从底向上回溯
        while (label >= 1) {
            res.push_back(label);
            int level_start = pow(2, level - 1);
            int level_end = pow(2, level) - 1;
            // 将当前层的Z字形label转换为正常标号
            int normal = level_start + level_end - label;
            // 计算父节点的Z字形标号
            label = normal / 2;
            level--;
        }
        // 反转结果得到从根到目标节点的路径
        reverse(res.begin(), res.end());
        return res;
    }
};

