class Solution {
public:
    bool rotateString(string A, string B) {
        
        if(A.length()!=B.length())
            return false;
        
        if(A.length()<2)
            return true;        
        deque<char> a(A.begin(), A.end());
        deque<char> b(B.begin(), B.end());
        
        for(int i=0;i<A.length();i++){
            if(a==b)
                return true;
            char ch = a.front();
            a.pop_front();
            a.push_back(ch);
            
        }
        
        return false;
    }
};