class Solution {
public:
    vector<vector<int>> generate(int n) {
        int arr[n][n];
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i)
                    arr[i][j]=1;
                else
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
        
        vector<vector<int>> ans;
        
        int line =0;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<=line;j++)
                temp.push_back(arr[i][j]);
            line++;
            ans.push_back(temp);
        }
        return ans;
    }
};