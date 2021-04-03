class Solution {
public:
    
    void solve(vector<int> &card, vector<int> &temp, vector<vector<int>> &ans, int index, int sum, int target){
        
        if(sum> target)
            return;
        
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        
        for(int i=index; i<card.size();i++){
            temp.push_back(card[i]);
            solve(card, temp, ans, i, sum+card[i], target);
            temp.pop_back();
        }
        
        return;
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        if(cand.size()==0)
            return ans;
        vector<int> temp;
        solve(cand, temp, ans, 0, 0, target);
        return ans;
    }
};