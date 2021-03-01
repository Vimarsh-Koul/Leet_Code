class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1, amount+1);
        // int temp = amount +1;
        // memset(dp, temp, sizeof(dp)); 
        dp[0]=0;
        // for(int i=0;i<=amount;i++)
        //     cout<<dp[i]<<"what the hell ";
        cout<<endl;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i)
                dp[i]= min(dp[i],1+ dp[i-coins[j]]);
                else
                    break;
            }
        }
        // for(int i=0;i<=amount;i++)
        //     cout<<dp[i]<<" ";
        return dp[amount]>amount ? -1: dp[amount];
    }
};