class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
int l = 0, r = numbers.size() - 1;
while (l < r) {
    int curSum = numbers[l] + numbers[r];
    if (curSum > target) {
        r--;
    } else if (curSum < target) {
        l++;
    } else {
        res.push_back(l + 1);
        res.push_back(r + 1);
        break;
    }
}
return res;

    }
};