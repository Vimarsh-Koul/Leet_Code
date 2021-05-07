class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        
        for(auto ch: num){
            while(!s.empty() && k>0 && s.top()> ch){
                s.pop(); 
                k--;
            }
            
            if(!s.empty() || ch!='0')
                s.push(ch);
        }
        
        while(!s.empty() && k>0){
            s.pop();
            k--;
        }
        
        string ans;
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        if(ans=="")
            return "0";
        
        return ans;
    }
};