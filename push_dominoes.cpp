class Solution {
public:
    string pushDominoes(string dom) {
        vector<int> forces(dom.size(), 0);
        int power = 0;
        int n = dom.size();
        
        for(int i=0;i<n;i++){
            
            if(dom[i]=='R')
                power = n;
            
            else if(dom[i]=='L')
                power = 0;
            
            else
                power = max(power-1, 0);
            
            forces[i]+= power;
        }
        
        power = 0;
        
        for(int i=n-1;i>=0;i--){
            
            if(dom[i]=='L')
                power = n;
            
            else if(dom[i]=='R')
                power = 0;
            else
                power = max(power-1, 0);
            
            forces[i]-= power;
        }
        
        string ans;
        
        for(auto it: forces){
            if(it>0)
                ans.push_back('R');
            else if(it < 0)
                ans.push_back('L');
            else
                ans.push_back('.');
        }
        
        return ans;
        
    }
};