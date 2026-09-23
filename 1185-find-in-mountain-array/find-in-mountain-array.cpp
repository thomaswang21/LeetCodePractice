/**
 * // 这就是 MountainArray 的 API 接口。
 * // 你不需要实现它，也不需要猜测它的实现
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // 第一步：寻找山峰（最大值）的索引
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // 如果 mid 的值小于 mid + 1 的值，说明当前处于“上坡”阶段，山峰在右侧
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            } else {
                // 否则说明处于“下坡”阶段，或者 mid 本身就是山峰，山峰在左侧或当前位置
                r = mid;
            }
        }
        int peak = l; // 退出循环时 l == r，这就是山峰的坐标
        
        // 第二步：在左半部分（严格递增区间）使用我们熟悉的闭区间模板找 target
        int left_index = searchAscending(target, mountainArr, 0, peak);
        if (left_index != -1) {
            // 题目要求返回最小的索引，既然左边找到了，就直接返回，不需要再找右边
            return left_index; 
        }
        
        // 第三步：如果左边没找到，再去右半部分（严格递减区间）找 target
        return searchDescending(target, mountainArr, peak + 1, n - 1);
    }

private:
    // 熟悉的闭区间二分模板（用于升序数组）
    int searchAscending(int target, MountainArray &mountainArr, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int mid_val = mountainArr.get(mid);
            
            if (mid_val == target) {
                return mid;
            } else if (mid_val < target) {
                l = mid + 1; // 升序：当前值太小，往右找
            } else {
                r = mid - 1; // 升序：当前值太大，往左找
            }
        }
        return -1;
    }
    
    // 熟悉的闭区间二分模板（用于降序数组）
    int searchDescending(int target, MountainArray &mountainArr, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int mid_val = mountainArr.get(mid);
            
            if (mid_val == target) {
                return mid;
            } else if (mid_val > target) {
                l = mid + 1; // 【注意这里】：降序数组越往右越小！当前值比目标大，必须往右找更小的
            } else {
                r = mid - 1; // 降序：当前值比目标小，必须往左找更大的
            }
        }
        return -1;
    }
};