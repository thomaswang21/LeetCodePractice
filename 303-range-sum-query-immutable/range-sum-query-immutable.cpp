class NumArray {
private:
    vector<int> prefixSums;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        // Create an array of size n + 1 initialized to 0.
        // prefixSums[i] will store the sum of elements from nums[0] to nums[i - 1].
        prefixSums.resize(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // The sum from index 'left' to 'right' is the sum up to 'right' 
        // minus the sum up to 'left - 1'.
        return prefixSums[right + 1] - prefixSums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */