class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Pointer for the last valid element in nums1
        int p1 = m - 1;
        // Pointer for the last element in nums2
        int p2 = n - 1;
        // Pointer for the last position in the merged array (nums1)
        int p = m + n - 1;

        // While both arrays have elements to compare
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // If there are still elements left in nums2, copy them over.
        // (If elements are left in nums1, they are already in the correct place)
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};