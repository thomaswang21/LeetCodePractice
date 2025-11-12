
// 思路：
// 1. 首先通过二分查找找到山峰的索引（即最大值所在位置）。
// 2. 然后在山峰左侧（递增部分）进行一次二分查找。
// 3. 如果未找到，再在山峰右侧（递减部分）进行一次二分查找。
// 4. 返回最小的索引，如果都找不到则返回 -1。

class Solution {
public:
    // 二分查找山峰位置
    int findPeak(MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);
            int nextVal = mountainArr.get(mid + 1);
            if (midVal < nextVal) {
                left = mid + 1; // 峰值在右边
            } else {
                right = mid; // 峰值在左边或当前位置
            }
        }
        return left; // left == right 即为峰值索引
    }

    // 在递增或递减区间进行二分查找
    int binarySearch(MountainArray &mountainArr, int target, int left, int right, bool ascending) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target) {
                return mid;
            }
            if (ascending) {
                if (midVal < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (midVal > target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr); // 找到山峰索引
        int index = binarySearch(mountainArr, target, 0, peak, true); // 左侧递增部分查找
        if (index != -1) {
            return index;
        }
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false); // 右侧递减部分查找
    }
};
