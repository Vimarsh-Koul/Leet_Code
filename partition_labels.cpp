class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> map;
        vector<int> ans;
        if(s.length()==0)
            return ans;
        int last =0;
        for(int i=0;i<s.length();i++)
            map[s[i]]=i;
        
        for(int i=0;i<s.length();i++){
            cout<<i<<endl;
            int lim = map[s[i]];
            for(int j=i+1;j<=lim;j++){
                if(map[s[j]]>lim)
                    lim= map[s[j]];
            }
            // cout<<lim<<endl;
            ans.push_back(lim+1-i);
            i=lim;
            
        }
        return ans;
    }
};