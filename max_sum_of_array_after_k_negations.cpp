class Solution {
public:
    int largestSumAfterKNegations(vector<int>& a, int K) {
        
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto it: a){
                pq.push(it);
        }
        
        if(pq.empty())
            return ans;
        
        for(int i=0;i<K;i++){
            int t = pq.top();
            pq.pop();
            if(t==0){
                pq.push(t);
                continue;
            }
            
            t= -t;
            pq.push(t);
        }
        
        while(!pq.empty()){
            ans+= pq.top();
            pq.pop();
        }
        return ans;
    }
};