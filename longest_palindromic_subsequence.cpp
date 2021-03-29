class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s=="")
            return 0;
        
        int dp[s.length()][s.length()];
        memset(dp,0,sizeof(dp));
        
        int ms =0;
        
        for(int g=0;g<s.length();g++){
            for(int i=0,j=g;j<s.length();i++,j++){
                if(g==0)
                    dp[i][j]=1;
                
                else if(g==1)
                    dp[i][j] = (s[i]==s[j])?2:1;
                
                else{
                    if(s[i]==s[j])
                        dp[i][j] = 2+ dp[i+1][j-1];
                    else
                        dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
                
                if(dp[i][j]>ms)
                    ms= dp[i][j];
            }
        }
        
        return ms;
    }
};