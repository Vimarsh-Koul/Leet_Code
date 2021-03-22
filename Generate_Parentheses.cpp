class Solution {
public:
    
    void permute(string a, int open, int close, int length, vector<string> &ans){
        if(open<0 || close<0)
            return;
        if(a.length()==length){
            // cout<<a<<endl;
            ans.push_back(a);
            return;
        }
        
        if(open>0)
            permute(a+'(', open-1, close, length, ans);
        if(close>open)
            permute(a+')', open,close-1, length, ans);
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        permute("",n,n,2*n, ans);
        return ans;
    }
};