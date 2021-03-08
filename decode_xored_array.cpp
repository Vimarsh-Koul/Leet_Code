class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans={first};
        int val = first;
        for(auto it: encoded){
            val= val^it;
            ans.push_back(val);
        }
        
        return ans;
    }
};