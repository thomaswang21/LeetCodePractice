class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9; // 改为双闭区间 [l, r]，最大值取 10^9
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (f(piles, mid) <= h) {
                // 当前速度 mid 能吃完，但我们要找更小的速度，所以向左逼近
                r = mid - 1;
            } else {
                // 当前速度 mid 吃不完，太慢了，必须向右寻找更大的速度
                l = mid + 1;
            }
        }
        
        // 循环跳出时，l 永远指向“第一个满足条件（即时间 <= h）的位置”
        return l; 
    }

private:
    long f(vector<int>& piles, int x) {
        long hours = 0;
        for (int p : piles) {
            hours += p / x;
            if (p % x > 0) hours++;
        }
        return hours;
    }
};