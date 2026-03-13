class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int sum=0;
        while(l<=r){
            sum=max(sum, min(height[l], height[r])*(r-l));
            if(height[l]<height[r])l++;
            else{
                r--;
            }
        }
        return sum;
    }
};