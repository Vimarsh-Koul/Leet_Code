class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i,j;
        i=j=0;
        int maxlen=0;
        int tempk =1;
        int n = nums.size();
        
        while(i<n and j<n){
            
            if(nums[j]==1){
                j++;
            }
            
            else if(nums[j]==0 and tempk<=k){
                j++;
                tempk++;
            }
            
            
            else if(nums[j]==0 and tempk > k){
                maxlen = max(maxlen, j-i);
                while(i<=j and tempk>k){
                    if(nums[i]==0)
                        tempk--;
                    i++;
                }
            }
  
        }
        
        maxlen = max(maxlen, j-i);
        return maxlen;
    }
};