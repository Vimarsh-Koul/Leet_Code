class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];
        
        string ans ="";
        
        string first = strs[0];
        // int index = 0;
        for(int i=0;i<first.length();i++){
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].length() || first[i]!=strs[j][i])
                    return ans;
            }
            ans += first[i];
            
        }
        return ans;
    }
};