class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
         vector<vector<int>> ans;
        if(nums.size()==0 || nums.size()==1 || nums.size()==2)
            return ans;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int low = i+1;
            int high = n-1;
            int target = -nums[i];
            
            while(low<high){
                if(nums[low]+nums[high] == target){
                    
                    vector<int>temp {nums[low], nums[high], nums[i]};
                    ans.push_back(temp);
                
                
                while(low<high && nums[low]==nums[low+1])
                    low++;
                while(low<high && nums[high]==nums[high-1])
                    high--;
                    
                low++;high--;
            }
                
            else{
                    if(nums[low]+nums[high]>target)
                        high--;
                    else
                        low++;
                }
            } 
        }
        return ans;
    }
};