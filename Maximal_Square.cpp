class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       int dp[matrix.size()][matrix[0].size()];
        int ans =0;
        
        for(int i=0;i<matrix.size();i++){
            dp[i][matrix[0].size()-1] = matrix[i][matrix[0].size()-1]-'0';
        }
        
        for(int i=0;i<matrix[0].size();i++){
            dp[matrix.size()-1][i] = matrix[matrix.size()-1][i]-'0';
        }
        
        
        for(int i= matrix.size()-2;i>=0;i--){
            for(int j = matrix[0].size()-2;j>=0;j--){
                if(matrix[i][j]=='0'){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]})+1;
                ans = max(dp[i][j], ans);
            }
        }
        
        for(int i=0;i<matrix.size();i++)
            for(int j =0;j<matrix[0].size();j++)
                ans= max(ans, dp[i][j]);

        return  ans*ans;
    }
};