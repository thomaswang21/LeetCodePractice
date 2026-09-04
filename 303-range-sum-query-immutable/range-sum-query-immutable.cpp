class NumArray {
public:
    vector<int> prefixSums;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSums.resize(n + 1, 0);
        
        // 修正 1: 循环要走到 n，所以用 <= nums.size() 或者 i < n + 1
        for(int i = 1; i <= nums.size(); i++){
            prefixSums[i] = prefixSums[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        // 修正 2: 因为我们在 prefixSums 前面垫了一个 0，所以所有的查询索引都要 +1
        // 这样即使 left 是 0，对应取的也是 prefixSums[0]，不会越界
        return prefixSums[right + 1] - prefixSums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */