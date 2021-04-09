class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        if(s.length()==0 || t.length()==0)
            return ans;
        
        unordered_map<char,int> map1, map2;
        for(auto it: t)
            map1[it]++;
        
        int i,j;
        i=j=-1;
        
        int m =0;
        int d = t.length();
        
        while(true){
            bool f1 = false;
            bool f2 = false;
            
            while((i+1<s.length()) && m<d){
                i++;
                map2[s[i]]++;
                
                if(map2[s[i]]<=map1[s[i]])
                    m++;
                f1 = true;
            }
            while(j<=i && m==d){
                string temp = s.substr(j+1, i-j);
                if(ans.length()==0 || ans.length()> temp.length())
                    ans = temp;
                
                j++;
                if(map2[s[j]]==1)
                    map2.erase(s[j]);
                else
                    map2[s[j]]--;
                
                if(map1[s[j]] > map2[s[j]])
                    m--;
                f2 = true;
            }
            
            if(!f1 && !f2)
                break;
        }
        return ans;
    }
};