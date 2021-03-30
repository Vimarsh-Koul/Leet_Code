

class Solution {
public:
    
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &memo){
        // if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size())
        //     return 0;
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        int len=0;
        
        if(i-1>=0 && matrix[i-1][j]> matrix[i][j])
            len = max(len, dfs(matrix, i-1,j, memo));
        
        if(i+1<matrix.size() && matrix[i+1][j]> matrix[i][j])
            len = max(len, dfs(matrix, i+1,j, memo));
        
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
            len = max(len, dfs(matrix, i,j-1, memo));
        
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j])
            len = max(len, dfs(matrix, i,j+1, memo));
       
        len+=1;
        
        memo[i][j]= len;
        return len;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(), vector<int> (matrix[0].size(), -1));
        int length =0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
               int temp =  dfs(matrix, i, j, memo);
                length = max(length, temp);
            }
        }
        
        return length;
    }
};