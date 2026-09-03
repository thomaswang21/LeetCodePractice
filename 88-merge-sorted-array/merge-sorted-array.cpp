class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        
        // 像第二个代码一样，使用 || 把条件合并
        while (p1 >= 0 || p2 >= 0) {
            
            // 安全检查 + 比较逻辑：
            // 条件1：如果 p2 已经小于 0 了（说明 nums2 已经放完了，只能放 nums1）
            // 条件2：如果 p1 还没完 (p1 >= 0) 且 nums1 的当前值更大
            if (p2 < 0 || (p1 >= 0 && nums1[p1] > nums2[p2])) {
                nums1[p] = nums1[p1];
                p1--;
            } 
            // 否则（说明 nums1 已经放完了，或者 nums2 的值更大或相等）
            else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
    }
};