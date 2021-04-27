class Solution {
public:
    int minimumDeletions(string s) {
        int countb=0;
        int ans =0;
        
        for(auto it: s){
            if(it=='a' && countb>0){
                countb--;
                ans++;
            }    
            
            else if(it=='b')
                countb++;
        }
        
        return ans;
    }
};