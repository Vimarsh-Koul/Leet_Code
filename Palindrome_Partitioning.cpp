class Solution {
public:
    
    unordered_map<string, bool> map;
    
    bool ispalindrome(string s){
        int n =s.length()/2;
        for(int i=0;i<=(n -1);i++){
            if(s[i]!=s[s.length()-i-1])
                return false;
        }
        return true;
    }
    
    void solve(string s, vector<string> &temp, vector<vector<string>> &ans, int index){
        if(index>=s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            string t = s.substr(index, i-index+1);
            if(ispalindrome(t)){
                temp.push_back(t);
                solve(s, temp,ans, i+1);
                temp.pop_back();
            }   
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(s, temp, ans, 0);
        return ans;
    }
};