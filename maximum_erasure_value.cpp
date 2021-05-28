class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int i,j;
        i=j=0;
        unordered_map<int,int> map;
        int maxsum = 0;
        int sum =0;
        
        while(j<n){
            
            if(map.find(nums[j])==map.end()){
                map[nums[j]]=j;
                sum+= nums[j];
                j++;
            }
            
            else if(map.find(nums[j])!=map.end()){

                maxsum = max(sum, maxsum);
                int ele  = map[nums[j]]+1;
                
                while(i<ele){
                    sum-=nums[i];
                    map.erase(nums[i]);
                    i++;
                }
            }
        }
        
        maxsum = max(sum, maxsum);
        return maxsum;

            
    }
};