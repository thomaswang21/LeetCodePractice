class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left,right=0;
        int res=INT_MAX;
        int windowSum=0;
        while(right<nums.size()){
            windowSum+=nums[right];
            right++;
            while(windowSum>=target&&left<right){
                    res=min(res, right-left);
                    windowSum-=nums[left];
                    left++;
            }
        }
        if (res == INT_MAX) {
                return 0;
        } else {
                return res;
}

    }
};