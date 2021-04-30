class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        
        if(x==1 && y==1){
            if(bound>=2){
                ans.push_back(2);
                return ans;
            }
            return ans;
        }
        
            int large = max(x,y);
            int small = min(x,y);
        
            int limit = log(bound)/ log(large);
         unordered_map<int,bool> map;
        
        vector<int> temp;
        for(int i=0;i<=limit;i++)
            temp.push_back(pow(large, i));
        
        if(small ==1){
            for(auto it: temp){
                if(it+1<=bound)
                    ans.push_back(it+1);
            }
            
            return ans;
        }
        
        int limit0 = log(bound)/ log(small);
        
        for(int i=0;i<=limit0;i++){
            int val = pow(small, i);
            
            for(int j =0;j<temp.size();j++){
                if(val + temp[j]<= bound && map.find(val + temp[j])==map.end()){
                    ans.push_back(val+ temp[j]);
                    map[val + temp[j]] = true;
                }
            }
        }
       
        return ans;
        
        
    }
};