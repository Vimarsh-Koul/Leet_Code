class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(), 0);
        
        stack<int> s;
        
        for(int i=0;i<t.size();i++){
            int currtemp = t[i];
            while(!s.empty() && currtemp> t[s.top()]){
                int index = s.top();
                s.pop();
                ans[index] = i - index;
            }
            
            s.push(i);
        }
        
        return ans;
    }
};