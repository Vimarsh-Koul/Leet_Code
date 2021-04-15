class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        if(g.size()==0 || s.size()==0)
            return 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int ans =0;
        
        int i,j;
        i=j=0;
        
        while(i<g.size() && j<s.size()){
            if(s[j]>= g[i]){
               ans++;
                j++;i++;
            }
                
            else if(s[j]<g[i])
                j++;
    
        }
        
        return ans;
    }
};