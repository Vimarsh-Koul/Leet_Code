class Solution {
public:
    
    vector<string> ans;
    
    void solve(string &s, string curr, int index){
        if(curr.length()==s.length()){
            ans.push_back(curr);
            return;
        }
        
        if(isdigit(s[index])!=0)
            solve(s, curr + s[index], index+1);
        else{
            solve(s, curr+ char(tolower(s[index])), index+1);
            solve(s, curr + char(toupper(s[index])), index+1);
        }
        
        return;
        
    }
    
    vector<string> letterCasePermutation(string S) {
        ans.clear();
        if(S=="")
            return ans;
        solve(S, "",0);
        return ans;
    }
};