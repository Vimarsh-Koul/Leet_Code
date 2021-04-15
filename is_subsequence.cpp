class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.length()==0 && t.length()==0)
            return true;
        
        if(s.length()==0)
            return true;
        
        int i=0,j=0;
        
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                i++;j++;
            }
            else
                j++;
        }
        
        if(i==s.length())
            return true;
        return false;
    }
};