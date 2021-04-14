class Solution {
public:
    int minOperations(string s) {
        int check01, check10;
        
        check01 = check10 = 0;
        
        for(int i=0;i<s.length();i++){
            if(i%2==0 && s[i]!='0')
                check01++;
            
            else if(i%2!=0 && s[i]!='1')
                check01++;
        }
        
        for(int i=0;i<s.length();i++){
            if(i%2==0 && s[i]!='1')
                check10++;
            
            else if(i%2!=0 && s[i]!='0')
                check10++;
        }
        
        return min(check01, check10);
    }
};