class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size()==0)
            return 0;
        
        int n = nums.size();
        int dp[n+1][2001];
        memset(dp,0, sizeof(dp));
        int origin = 1000;
        dp[0][origin] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j = 0;j<2001;j++){
                if(dp[i-1][j] > 0){
                    dp[i][j + nums[i-1]] += dp[i-1][j];
                    dp[i][j-nums[i-1]] += dp[i-1][j];
                }
            }
        }
        
        return dp[n][1000+target];
    }
};