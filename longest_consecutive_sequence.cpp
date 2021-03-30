class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> map;
        for(auto it: nums)
            map[it]=true;
        
        int longest =0;
        
        for(auto it: map){
            if(map.find(it.first-1)==map.end()){
                int ele = it.first+1;
                int templ = 1;
                
                while(map.find(ele)!=map.end()){
                    ele++;
                    templ++;
                }
                
                longest = max(longest, templ);
            }
        }
        
        return longest;
    }
};