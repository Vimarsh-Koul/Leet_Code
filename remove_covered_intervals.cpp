class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
            return 1;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<intervals.size();i++){
            if(ans.size()==0){
                ans.push_back(intervals[i]);
                continue;
            }
            
            vector<int> temp = ans[ans.size()-1];
            
            if(intervals[i][0]>= temp[0] && intervals[i][1]<= temp[1])
                continue;
            
            else if(intervals[i][0]<=temp[0] && intervals[i][1]>= temp[1])
                ans[ans.size()-1] = intervals[i];
            
            else
                ans.push_back(intervals[i]);

        }
        
        return ans.size();
    }
};