class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> ans(1002, 0);
        
        
        for(int i=0;i<trips.size();i++){
            int start = trips[i][1];
            int end = trips[i][2];
            int count = trips[i][0];
            
            ans[start]+= count;
            ans[end]-= count;
        }
        
        for(int i=1;i<1002;i++)
            ans[i]+= ans[i-1];
        
        int m =0;
        
        for(auto it: ans)
            m = max(m,it);
        
        cout<<m<<endl;
        return m>capacity? false: true;
    }
};