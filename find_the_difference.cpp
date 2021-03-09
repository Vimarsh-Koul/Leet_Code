class Solution {
public:
    char findTheDifference(string s, string t) {
        int onum=0;
        char ans;
        for(int i=0;i<s.length();i++){
            onum^=(1<<(s[i]-'a'));
            // cout<<onum;
        }
            for(auto it: t){
                onum^=(1<<(it-'a'));
            }
        // char c = char(log2(onum)+97+1);
        for(auto it: t)
            if((onum&(1<<(it-'a')))==0)
                continue;
        else{
            ans =it;
            break;
        }
            
        return ans;
    
    }
};