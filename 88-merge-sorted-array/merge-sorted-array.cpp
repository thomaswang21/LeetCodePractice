class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;       // 指向 nums1 中实际数字的末尾
        int p2 = n - 1;       // 指向 nums2 的末尾
        int p = m + n - 1;    // 指向 nums1 数组的最末尾（放置大数的位置）

        // 当两个数组都还有元素时进行比较
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;  // 无论谁大，放置好元素后，目标位置指针都要前移
        }

        // 扫尾工作：如果 nums2 还有剩余，直接复制到 nums1 前面
        // (如果 nums1 还有剩余则不需要处理，因为它们本来就在 nums1 里)
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};