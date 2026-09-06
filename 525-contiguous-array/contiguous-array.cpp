class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>sumToIndex;
        sumToIndex[0] = -1;
        int currentSum = 0;
        int maxLength = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                currentSum -= 1;
            }else{
                currentSum += 1;
            }
            if(sumToIndex.find(currentSum) != sumToIndex.end()){
                maxLength = max(maxLength, i - sumToIndex[currentSum]);
            }else{
                sumToIndex[currentSum] = i;
            }
        }
        return maxLength;
    }
};