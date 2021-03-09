class Solution {
public:
    int numSplits(string s) {
        if(s=="")
            return 0;
        
        unordered_map<char,int> m0,m1;
        // for(auto it: s)
        //     m1[it]++;
        
        for(int i=1;i<s.length();i++)
            m1[s[i]]++;
        
        m0[s[0]]++;
        int ans =0;
        
        if(m0.size()==m1.size())
            ans++;
        
        for(int i=1;i<s.length();i++){
            char c = s[i];
            m0[c]++;
            m1[c]--;
            
            if(m1[c]<=0)
                m1.erase(c);
            
            if(m0.size()==m1.size())
                ans++;
        }
        
        return ans;
    }
};