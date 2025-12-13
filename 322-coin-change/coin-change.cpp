class Solution {
public:
    int inf=100000000;
    int coinChange(vector<int>& coins, int amount) {
        vector<int>f(amount+1, inf);
        f[0]=0;
        for(int i=0; i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                f[j]=min(f[j], f[j-coins[i]]+1);

            }
        }
        if(f[amount]==inf)f[amount]=-1;
        return f[amount];
    }
};