class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> m0;
        for(int i=0;i<stones.size();i++)
            m0[stones[i]]=i;
        unordered_map<int,unordered_set<int>> map= {{stones[0],{0}}};
        
        for(int i=0;i<stones.size();i++){
            if(map.find(stones[i])==map.end())
                continue;
            
            if(map.find(stones[stones.size()-1])!=map.end())
                return true;
            
            for(int jumps: map[stones[i]]){
                
                    for(int k = jumps-1;k<=jumps+1;k++){
                        if(m0[stones[i]+k]!=0){
                            map[stones[i]+k].insert(k);
                        }
                    }
                
            }
        }
        if(map.find(stones[stones.size()-1])==map.end())
            return false;
        return true;
    }
};