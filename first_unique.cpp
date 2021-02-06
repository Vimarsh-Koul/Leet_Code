class Solution {
public:
    int firstUniqChar(string s) {
        int chars[26];
        int a[26];
        memset(a,-1,sizeof(a));
        
        for(int i=0;i<s.length();i++){
            if(a[int(s[i])-97]==-1)
                a[int(s[i])-97]=1;
            else
                a[int(s[i])-97]+=1;
        }
    
    
    for(int i=0;i<s.length();i++){
        if(a[int(s[i])-97]==1)
            return i;
    }
    
    return -1;
    }
};