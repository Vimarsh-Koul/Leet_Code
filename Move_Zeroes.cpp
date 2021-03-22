class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        int n = nums.size();
        i=0;
        while(i<n){
            while(i<n && nums[i]!=0){
                i++;
            }
               
            if(i==n){
                break;
            }
                
            int start = i;
            i++;
            j=i;
            while(j<n && nums[j]==0)
                j++;
            
            if(j==n){
                break;
            }
            swap(nums[start],nums[j]);
        }
    }
};