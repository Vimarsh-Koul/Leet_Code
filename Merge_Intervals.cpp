bool comp(const vector<int> &a, const vector<int> &b){
        return a[0]< b[0];
    }

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<int> current = intervals[0];
        vector<vector<int>> ans;
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=current[1])
                current[1] = max(current[1], intervals[i][1]);
            
            else{
                ans.push_back(current);
                current = intervals[i];
            }
        }
            ans.push_back(current);
        return ans;
    }
};