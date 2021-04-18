class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> map;
        
        if(k> s.length())
            return false;
        
        for(char it: s)
            map[it]++;
        
        int count =0;
        
        for(auto it : map){
            if(it.second%2!=0)
                count++;
            
            if(count> k)
                return false;
        }
        
        return true;
    }
};