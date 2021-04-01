//  using extra space

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left[n];
        int right[n];
        
        left[0]= nums[0];
        right[n-1]= nums[n-1];
        
        for(int i=1;i<n;i++)
            left[i] = nums[i]+ left[i-1];
        
        for(int i=n-2;i>=0;i--)
            right[i] = nums[i]+ right[i+1];
        
        
        
        for(int i=0;i<n;i++){
            if(left[i]==right[i])
                return i;
        }
        
            return -1;
    }
};

//  using constant space

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto it: nums)
            sum+=it;
        int leftsum =0;
        
        for(int i=0;i<nums.size();i++){
            if(leftsum == sum-leftsum-nums[i]) 
                return i;
            leftsum+= nums[i];
        }
        return -1;
    }
};