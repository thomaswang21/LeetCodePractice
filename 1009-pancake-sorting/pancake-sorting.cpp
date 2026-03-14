

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res; // 存储每次翻转的k值
        int n = arr.size();

        // 从大到小依次将最大值放到正确位置
        for (int curr = n; curr > 1; curr--) {
            // 找到当前最大值的位置
            int idx = max_element(arr.begin(), arr.begin() + curr) - arr.begin();

            // 如果已经在正确位置，跳过
            if (idx == curr - 1) continue;

            // 如果最大值不在最前面，先翻转到最前
            if (idx != 0) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                res.push_back(idx + 1);
            }

            // 再翻转到正确位置
            reverse(arr.begin(), arr.begin() + curr);
            res.push_back(curr);
        }

        return res;
    }
};

