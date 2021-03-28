class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxhere,minhere, maxoverall;
        maxhere = minhere = maxoverall = nums[0];
        
        for(int i=1;i<nums.size();i++){
            int temp = maxhere;
            maxhere = max({nums[i], nums[i]*maxhere, nums[i]*minhere});
            minhere = min({nums[i], nums[i]*temp, nums[i]*minhere});
            maxoverall = max(maxoverall, maxhere);
        }
        return maxoverall;
    }
};