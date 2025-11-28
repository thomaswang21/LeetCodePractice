class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1;
        for (int i = 1, up = 1, down = 1; i < arr.size(); i ++ ) {
            if (arr[i] > arr[i - 1]) {
                up = down + 1;
                down = 1;
            } else if (arr[i] < arr[i - 1]) {
                down = up + 1;
                up = 1;
            } else {
                down = up = 1;
            }
            res = max(res, max(up, down));
        }
        return res;
    }
};
