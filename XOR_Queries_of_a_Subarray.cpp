class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
            vector<int> ans;
        if(arr.size()==0)
            return ans;
        
        for(int i=1;i<arr.size();i++)
            arr[i]^=arr[i-1];
        
        for(int i=0;i<queries.size();i++){
            int lq = queries[i][0];
            int rq = queries[i][1];
            
            if(lq==0)
                ans.push_back(arr[rq]);
            else
                ans.push_back(arr[rq]^arr[lq-1]);
        }
        
        return ans;
    }
};