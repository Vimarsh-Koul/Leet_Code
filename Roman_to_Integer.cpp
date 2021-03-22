class Solution {
public:
    
    int element(char ch){
        switch(ch){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i==0)
                ans+=element(s[i]);
            else{
                if((s[i]=='V' || s[i]=='X') && s[i-1]=='I')
                    ans+= abs(2*element(s[i-1])-element(s[i]));
                else if((s[i]=='L' || s[i]=='C') && s[i-1]=='X')
                    ans+= abs(2*element(s[i-1])-element(s[i]));
                else if((s[i]=='D' || s[i]=='M') && s[i-1]=='C')
                    ans+= abs(2*element(s[i-1])-element(s[i]));   
                else
                    ans+=element(s[i]);
            }
        }
        
        return ans;
    }
};