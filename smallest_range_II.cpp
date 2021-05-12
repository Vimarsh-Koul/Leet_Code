class Solution {
public:
    int smallestRangeII(vector<int>& a, int k) {
        
        if(a.size()==1)
            return 0;
        sort(a.begin(), a.end());    
        int ans = a[a.size()-1] - a[0];
        
        for(int i=0;i<a.size()-1;i++){
            int num1 = max(a[a.size()-1]-k, a[i]+k);
            int num2 = min(a[0] + k,  a[i+1]-k);
            ans = min(ans, (num1-num2));
        }
        
        return ans;
    }

};