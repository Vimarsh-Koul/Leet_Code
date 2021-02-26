class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size()==0)
            return ans;
        unordered_map<string, vector<string>> map;
        
        for(int i=0;i<strs.size();i++){
            string org = strs[i];
            string temp = org;
            sort(temp.begin(),temp.end());
            map[temp].push_back(org);
        }
        
        for(auto it: map)
            ans.push_back(it.second);
        
        return ans;
    }
};