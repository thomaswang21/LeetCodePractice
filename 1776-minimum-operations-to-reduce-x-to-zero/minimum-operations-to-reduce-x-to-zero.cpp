class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total_sum=0;
        for(int num:nums)total_sum+=num;
        long long target=total_sum-x;
        if(target<0)return -1;
        if(target==0)return nums.size();
        int n=nums.size();
        int current_sum=0;
        int left=0;
        int max_len=-1;
        for(int right=0; right<n;right++){
            current_sum+=nums[right];
            while(current_sum>target&&left<right){
                current_sum-=nums[left];
                left++;

            }
            if(current_sum==target){
                max_len=max(max_len,right-left+1);
            }
            
        }
        if(max_len==-1)return -1;
        return n-max_len;
    }
};