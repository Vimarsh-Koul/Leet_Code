class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        int size = nums.size();
        if(nums.size()==0)
            return ans;
        for(int i=0;i<size;i++)
            nums.push_back(nums[i]);
        
        stack<pair<int,int>> s;
        
        for(int i=0;i<nums.size();i++){
            
            if(s.empty() || s.top().first>= nums[i]){
                s.push({nums[i],i});
                continue;
            }
            
            while(!s.empty() && s.top().first< nums[i]){
                if(s.top().second>=size){
                    s.pop();continue;
                }
                
                ans[s.top().second] = nums[i];
                s.pop();     
            }
            s.push({nums[i], i});
        }
        return ans;
    }
};