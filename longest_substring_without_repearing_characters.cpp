class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        int i=0,j=0;
        unordered_map<char,int> map;
        int mlength=0;
        int c =0;
        int n = s.length();
        while(i<n){
            if(!map[s[i]]){
                map[s[i]]++;
                c++;
                mlength = max(mlength, c);
                i++;
            }
            
            else{
                map[s[j]]--;
                c--;
                j++;
            }
        }
        
        return mlength;
    }
};