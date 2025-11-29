class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
        if(a.empty()) return res;

        sort(a.begin(), a.end()); // 按左端点排序
        int l = a[0][0], r = a[0][1];

        for(int i = 1; i < a.size(); i++){
            if(a[i][0] > r){
                res.push_back({l, r}); // 推入上一个区间
                l = a[i][0];
                r = a[i][1];
            } else {
                r = max(r, a[i][1]); // 合并区间
            }
        }

        res.push_back({l, r}); // 循环结束后推入最后一个区间
        return res;
    }
};
