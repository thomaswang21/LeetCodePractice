class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        
        int left_max = 0;
        int right_max = 0;
        
        int trapped_water = 0;
        
        while (left < right) {
            // The smaller height determines how much water can be trapped
            if (height[left] < height[right]) {
                if (height[left] > left_max) {
                    left_max = height[left]; // Update max on the left
                } else {
                    trapped_water += left_max - height[left]; // Add water
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right]; // Update max on the right
                } else {
                    trapped_water += right_max - height[right]; // Add water
                }
                right--;
            }
        }
        
        return trapped_water;
    }
};