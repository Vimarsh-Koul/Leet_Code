class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
                vector<int> circles(nums.size(), 0);
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            if(nums[i] > 0)
                circles[i] = (nums[i] + i)%n;
            
            else{
                int temp = (abs(nums[i])+(n-i-1))%n;
                circles[i] = n-1-temp;
            }
        }
        
        for(int i=0;i<circles.size();i++){
            int count = 0;
            
            int fast,slow;
            fast = slow = i;
            while(true){
                
               slow = circles[slow];
                fast = circles[fast];
                
                if(nums[slow] < 0 and nums[fast] > 0 or nums[slow] > 0 and nums[fast] < 0)
                    break;
                
                fast = circles[fast];
                
                 if(nums[slow] < 0 and nums[fast] > 0 or nums[slow] > 0 and nums[fast] < 0)
                    break;

                if(slow == fast and slow == circles[slow])
                    break;
                
                else if(slow == fast)
                    return true;
                
            }
        }
         return false;
    }
};