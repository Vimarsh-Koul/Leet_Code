class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        
        if(!firstList.size() and !secondList.size())
            return ans;
        
        int i,j;
        i = j = 0;
        
        int m = firstList.size();
        int n = secondList.size();
        
        while(i<m and j<n){
            cout<<i<<" "<<j<<endl;
            if(max(firstList[i][0], secondList[j][0]) <= min(firstList[i][1], secondList[j][1]))
            ans.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            
           if(firstList[i][1] < secondList[j][1])
                i++;
        
            else
                j++;
        }
        
        return ans;
    }
};