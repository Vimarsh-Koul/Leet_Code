class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()==0 && nums.size()==1)
            return true;
        bool check = false;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1] && !check){
                check = true;
                if(i-1==0)
                    continue;

                    if(nums[i-2] > nums[i]){
                     nums[i] = nums[i-1];   
                    }
                
                else if(nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
            }
            
            else if(nums[i] < nums[i-1] && check)
                return false;
            
                
        }
 
        return true;
    }
};