bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.second > p2.second;
}

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        int mod = 1000000007;
        
        vector<pair<int,int>> se;
        for(int i=0;i<speed.size();i++){
            pair<int,int> p = {speed[i], efficiency[i]};
            se.push_back(p);
        }
        
        sort(se.begin(), se.end(), comp);
        long long int  ans =0, curr = 0;
        priority_queue<int, vector<int>, greater<int>> p;
        
        for(int i=0;i<se.size();i++){
            
            if(p.size() > k-1){
                curr -= p.top();
                p.pop();
            }
            
            p.push(se[i].first);
            curr += se[i].first;
            ans = max(ans, curr * se[i].second);
            
        }
        
        return ans%mod;
    }
};