class Solution {
public:
    
    vector<int> find(vector<int> &nums, int i, int target){
        int j =i;
        while(j<nums.size() && nums[j]==target)
            j++;
        
        while(i>=0 && nums[i]==target)
            i--;
        
        vector<int> ans;
        ans.push_back(i+1);
        ans.push_back(j-1);
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp = {-1,-1};
        if(nums.size()==0)
            return temp;
        
        int left,right;
        left =0;
        right = nums.size()-1;
        while(left<=right){
            
            int mid = left + (right-left)/2;

            if(nums[mid]==target)
               return find(nums, mid, target);
            
                
            else if(nums[mid]>target)
                right = mid - 1;
            
            else
                left = mid + 1;
        }
        return temp;
    }
};