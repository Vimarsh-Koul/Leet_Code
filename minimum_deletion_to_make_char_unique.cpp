
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int> map;
        unordered_map<char,int> map1;
        
        vector<pair<char, int>> vec;
        
        for(auto it: s)
            map1[it]++;
        
        for(auto it: map1)
            vec.push_back({it.first, it.second});
        
        for(auto it: map1)
            map[it.second]++;
        
        int ans =0;
        for(int i=0;i<vec.size();i++){
            int count = vec[i].second;
            int temp = count;
            
            if(map[count]==1)
                continue;
            
            else{
                while(map.find(temp)!=map.end()){
                    temp--;
                    ans++;
                }
                
                map[count]--;
                if(temp==0)
                    continue;
                
                map[temp]++;
            }
        }
        
        return ans;
    }
};