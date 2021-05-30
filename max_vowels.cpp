class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,bool> map;
        
        map['a'] = true;
        map['e'] = true;
        map['i'] = true;
        map['o'] = true;
        map['u'] = true;
        
        int len, maxlen;
        len = maxlen = 0;
        
        for(int i=0;i<s.length();i++){
            
            if(map[s[i]])
                len++;
            
            if(i>=k and map[s[i-k]])
                len--;
            
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};