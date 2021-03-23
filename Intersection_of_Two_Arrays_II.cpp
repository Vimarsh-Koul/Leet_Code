class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        unordered_map<int,int> map;
        
        for(auto it: nums1)
            map[it]++;
        
        for(auto it: nums2){
            if(map[it]){
                ans.push_back(it);
                map[it]--;
            }
        }
        
        return ans;
    }
};