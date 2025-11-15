class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> res;
        int k = 0;
        
        // 处理左边无交集的部分
        while (k < a.size() && a[k][1] < b[0]) {
            res.push_back(a[k]);
            k++;
        }

        // 处理重叠部分，合并区间
        if (k < a.size()) {
            b[0] = min(b[0], a[k][0]);
            while (k < a.size() && a[k][0] <= b[1]) {
                b[1] = max(b[1], a[k][1]);
                k++;
            }
        }
        res.push_back(b);

        // 处理右边无交集的部分
        while (k < a.size()) {
            res.push_back(a[k]);
            k++;
        }

        return res;
    }
};