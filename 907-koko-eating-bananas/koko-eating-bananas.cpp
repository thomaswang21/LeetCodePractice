class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9 + 1; // [left, right)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f(piles, mid) <= h) {
                right = mid;        // mid 可能是答案
            } else {
                left = mid + 1;     // mid 不可能是答案
            }
        }
        return left;
    }

    long f(vector<int>& piles, int x) {
        long hours = 0;
        for (int p : piles) {
            hours += p / x;
            if (p % x > 0) hours++;
        }
        return hours;
    }
};
