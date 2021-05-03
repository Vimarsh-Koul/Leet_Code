bool course(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), course);
        priority_queue<pair<int,int>> pq;
        int count = 0;
        int time =0;
        
        for(int i=0;i<courses.size();i++){
            if(time+ courses[i][0] <= courses[i][1]){
                count ++;
                time += courses[i][0];
                pq.push({courses[i][0], i});
            }
            
            else if(!pq.empty() && pq.top().first > courses[i][0]){
                
                pair<int,int> p = pq.top();
                    pq.pop();
                    pq.push({courses[i][0], i});
                    time+= courses[i][0];
                    time -= courses[p.second][0];
                    courses[p.second][0] = -1;
            }
            else
                courses[i][0] = -1;
        }
        
        return count;
    }
};