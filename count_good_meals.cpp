
class Solution {
    
public:
    
    int countPairs(vector<int>& del) {
        
        int ans = 0;
        unordered_map<int,int> map;
        int powerof2;
        
        for(int i=0;i<=21;i++){
            
            if(i==0)
                powerof2 = 1;
            else
                powerof2 = powerof2 * 2;
            
            int num = powerof2;
            for(int i=0;i<del.size();i++){
                if(map.find(num - del[i])!=map.end())
                    ans = (ans + map[num-del[i]])%1000000007;
                map[del[i]]++;
            }
            map.clear();
        }
        return ans;
    }
};