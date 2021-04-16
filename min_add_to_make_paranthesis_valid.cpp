class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<char> s;
        
        for(auto it: str){
            if(it=='(')
                    s.push('(');

            else{
                if(!s.empty() && s.top()=='(')
                    s.pop();
                else
                    s.push(')');
            }
        }
        
        return s.size();
    }
};