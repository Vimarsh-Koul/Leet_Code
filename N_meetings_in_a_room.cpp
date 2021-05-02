class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
       vector<pair<int,int>> intervals;
       
       for(int i=0;i<n;i++){
           pair<int,int> p{start[i], end[i]};
           intervals.push_back(p);
       }
       
       sort(intervals.begin(), intervals.end(), interval);
        
        int count =1;
        int endtime = intervals[0].second;
        
        // for(auto it: intervals){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        for(int i=1;i<intervals.size();i++){
            
            // cout<<endtime
            
            if(intervals[i].first > endtime){
                endtime = intervals[i].second;
                count++;
            }
        }
        
        return count;
    }
};