vector<vector<int>> edges;
vector<int> counts;

int longest(int index){
    if(counts[index] > 0)
        return counts[index];
    
    counts[index] = 1;
    
    for(auto it : edges[index]){
        counts[index] = max(counts[index], longest(it)+1);
    }
    
    return counts[index];
}


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> map;
        int n = words.size();
        
        edges.clear(); counts.clear();
        edges.resize(n); counts.resize(n);
        
        for(int i=0;i<words.size();i++){
            map[words[i]] =i;
        }
        
        for(int i=0;i<n;i++){
            string s = words[i];
            
            for(int j=0;j<s.length(); j++){
                string check = s.substr(0, j) + s.substr(j+1, s.length());
                
                if(map.find(check)==map.end())
                    continue;
                
                edges[map[check]].push_back(i);
            }
        }
        
        int maxlen = 0;
        for(int i=0;i<n;i++){
            maxlen = max(maxlen, longest(i));
        }
        
        return maxlen;
    }
};