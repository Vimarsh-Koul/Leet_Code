class Solution {
public:
    int minimumSwap(string s1, string s2) {
        
        if(s1.length()!=s2.length())
            return -1;
        
        int countxy, countyx;
        countxy= countyx = 0;
        
        for(int i=0;i<s1.length();i++){
            if(s1[i]=='x' && s2[i]=='y')
                countxy++;
            else if(s1[i]=='y' && s2[i]=='x')
                countyx++;
        }
        
        if(((countxy%2) + (countyx%2))%2!=0)
            return -1;
        
        int ans = countxy/2 + countyx/2;
        ans += ((countxy%2) + (countyx%2));
        return ans;
    }
};