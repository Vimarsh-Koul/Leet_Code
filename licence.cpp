string solve(string finals,int k){
    
    string ans;
    
    int size =0;
    string temp;
    
    for(int i=finals.length()-1;i>=0;i--){
        
        if(finals[i]=='-')
            continue;
        
        if(size<k){
            temp.push_back(toupper(finals[i]));
            size++;
        }
        
        if(size == k){
            ans+= temp;
            if(i!=0)
                ans.push_back('-');
            temp="";
            size =0;
        }
    }
    
    if(temp!="")
        ans+=temp;
    
    reverse(ans.begin(), ans.end());
    
    if(ans[0]=='-')
        return ans.substr(1);
    
    return ans;
}


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        return solve(s, k);
        
    }
};