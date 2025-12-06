class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(int num:nums){
            hash.insert(num);
        }
        int longest = 0;

        for (int num : hash) { // 遍历 hash 而不是 nums，可以去重
            // 找到连续序列的起点
            if (!hash.count(num - 1)) {
                int current = num;
                int length = 1;

                // 向右扩展连续序列
                while (hash.count(current + 1)) {
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
