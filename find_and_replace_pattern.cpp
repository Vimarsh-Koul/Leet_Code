class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,char> from,to;
        vector<string> ans;
        int n = pattern.length();
        for(auto str : words){
            from.clear();
            to.clear();
            bool flag = true;
            for(int i=0;i<pattern.length();i++){

                if(from.find(pattern[i])==from.end() and to.find(str[i])==to.end()){
                    from[pattern[i]] = str[i];
                    to[str[i]] = pattern[i];
                    continue;
                }
                
                else if(from.find(pattern[i])!=from.end() and str[i]!=from[pattern[i]]){
                    flag = false;
                    break;
                }
                
                else if(from.find(pattern[i])==from.end() and to.find(str[i])!=to.end()){
                    flag = false;
                    break;
                }
                
                from[pattern[i]] = str[i];
                to[str[i]] = pattern[i];
                
            }
            
            if(flag)
                ans.push_back(str);
            
        }
        
        return ans;
    }
};