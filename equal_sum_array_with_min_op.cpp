class Solution {
public:
    
    int solve(vector<int> nums1, vector<int> nums2, int great, int small){
        int count=0;
        
        int i=nums1.size()-1;
        int j = 0;
        
        while(i>=0 || j<nums2.size()){
            if(great<=small) break;
            
            int change1=-1, change2 = -1;
            
            if(i>=0)
                change1 = nums1[i] - 1;
            
            if(j<nums2.size())
                change2 = 6 - nums2[j];
            
            if(change1 >= change2){
                great = great - nums1[i] + 1;
                i--;
            }
            
            else if(change2> change1){
                small = small - nums2[j] + 6;
                j++;
            }
            count++;
        }
        return count;
    }
    
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()*6 < nums2.size() || nums1.size() > nums2.size()*6)
            return -1;
        
        int sum1,sum2;
        sum1 = sum2 =0;
        
        for(auto it: nums1) sum1+= it;
        for(auto it: nums2) sum2+= it;
        
        if(sum1 == sum2)
            return 0;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        if(sum1 > sum2)
            return solve(nums1, nums2, sum1, sum2);
        
        return solve(nums2, nums1, sum2 , sum1);
    }
};