class Solution {
public:
    
    int solve(int val, vector<int> &a, vector<int> &b){
        int s=0;
        
        for(int i=0;i<a.size();i++){
            if(a[i]!=val && b[i]!=val){
                return INT_MAX;
            }
            else if(a[i]!=val)
                s++;
        }
        return s;
    }
    
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int m0 = min(solve(a[0], a, b), solve(b[0], a, b));
        m0 = min(m0, solve(a[0], b, a));
        m0 = min(m0, solve(b[0], b, a));
        
        return m0==INT_MAX? -1: m0;
    }
};