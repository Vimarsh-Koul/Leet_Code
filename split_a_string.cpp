class Solution {
public:
    int balancedStringSplit(string s) {
        int count =0;
        int l =0, r=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='L')
                l++;
            else if(s[i]=='R')
                r++;
            
            if(l-r == 0){
                count++;
                l=r=0;
            }
        }
        
        return count;
    }
};