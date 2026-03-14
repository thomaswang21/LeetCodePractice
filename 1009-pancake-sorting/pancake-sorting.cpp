

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res; // 存储每次翻转的k值
        int n = arr.size(); // 数组长度
        
        // 从最后一个位置开始逐步确定最大值的位置
        for (int currSize = n; currSize > 1; currSize--) {
            // 找到当前未排序部分的最大值下标
            int maxIndex = 0;
            for (int i = 1; i < currSize; i++) {
                if (arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }

            // 如果最大值已经在正确位置，则跳过
            if (maxIndex == currSize - 1) {
                continue;
            }

            // 如果最大值不在第一个位置，先翻转到前面
            if (maxIndex != 0) {
                reverse(arr.begin(), arr.begin() + maxIndex + 1); // 翻转前maxIndex+1个
                res.push_back(maxIndex + 1); // 记录翻转长度
            }

            // 再翻转到正确的末尾位置
            reverse(arr.begin(), arr.begin() + currSize);
            res.push_back(currSize);
        }

        return res; // 返回所有翻转操作
    }
};

