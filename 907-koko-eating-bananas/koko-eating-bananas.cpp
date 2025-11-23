class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=1e9+1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(f(piles, mid)<=h){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
    long f(vector<int>&piles, int x){
        long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=piles[i]/x;
            if(piles[i]%x>0){
                hours++;
            }
        }
        return hours;
    }
};