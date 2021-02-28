class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0)
            return ans;
        
        vector<int> temp;
        ans.push_back(temp);
        
        int p = pow(2, nums.size());
        for(int i=1;i<p;i++){
            temp.clear();
            for(int j =0;j<nums.size();j++){
                if(i & (1<<j))
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};