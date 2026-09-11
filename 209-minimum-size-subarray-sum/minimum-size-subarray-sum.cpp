class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int currentSum =0 ;
        int left = 0;
        int min_length =INT_MAX;
        for(int right = 0; right < n ; right++){
            currentSum += nums[right];
            while(currentSum >= target){
                min_length = min(min_length, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }
        if(min_length == INT_MAX){
            return 0;
        }
        return min_length;
    }
};