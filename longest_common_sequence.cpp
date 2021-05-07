class Solution {
public:
    int longestCommonSubsequence(string word1, string word2) {
        
        if(word1.length()== 1 && word2.length()==1){
            if(word1[0]==word2[0])
                return 1;
            return 0;
        }
        
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        int m = INT_MIN;

        for(int i=1;i<=word1.length();i++){
            for(int j =1; j<=word2.length();j++){
                
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                m = max(m, dp[i][j]);
                
            }
        }
        
        return m;
    }
};