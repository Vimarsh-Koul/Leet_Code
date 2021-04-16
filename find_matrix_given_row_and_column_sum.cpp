class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowsum, vector<int>& colsum) {
        vector<vector<int>> ans(rowsum.size(), vector<int> (colsum.size(), 0));
        int i=0,j=0;
        
        while(i<rowsum.size() && j<colsum.size()){
            int temp = min(rowsum[i], colsum[j]);
            rowsum[i]-= temp;
            colsum[j]-= temp;
            
            ans[i][j] = temp;
            if(rowsum[i]==0)
                i++;
            else
                j++;
        }
        
        return ans;
    }
};