class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int i,j;
        i=j=0;
        
       unordered_map<int,int> map;
        int maxans =0;
        while(j<tree.size()){
            
            map[tree[j]]++;
            
            if(map.size() > 2){
                maxans = max(maxans , j-i);
                
                int ele = tree[i];
                
                while(tree[i]==ele){
                    i++;
                    map[ele]--;
                }
                if(map[ele]<=0)
                    map.erase(ele);
            }
            j++;
        }
        
        maxans = max(maxans, j-i);
        
        return maxans;
    }
};