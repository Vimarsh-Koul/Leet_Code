class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int x = 0;
        for(auto it: nums)
            x^=it;
        int num1=0;
        int num2 =0;
        x= x & -x;
        
        for(auto it: nums){
            if((it & x)==0)
                num1^=it;
            else
                num2^=it;
        }
        
        vector<int> ans= {num1, num2};
        return ans;
    }
};