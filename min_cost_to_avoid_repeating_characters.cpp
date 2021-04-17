class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans=0;
        
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                int curr = -1;
                while(i<s.length()-1 && s[i]==s[i+1]){
                    if(curr== -1){
                        ans += min(cost[i], cost[i+1]);
                        curr = max(cost[i], cost[i+1]);
                    }
                    
                    else{
                        ans += min(curr, cost[i+1]);
                        curr = max(curr, cost[i+1]);
                    }
                    i++;
                }
            }
        }
        
        return ans;
    }
};