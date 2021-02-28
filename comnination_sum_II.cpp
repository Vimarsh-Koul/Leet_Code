class Solution {
public:
    
    void solve(vector<vector<int>> &ans, vector<int> &temp, int index,int target, vector<int> & candi ){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(target<0)
            return;
        for(int i=index;i<candi.size();i++){
            if(i==index || candi[i]!=candi[i-1]){
                 temp.push_back(candi[i]);
                solve(ans, temp, i+1, target-candi[i], candi);
                temp.pop_back();
            }
           
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        if(candidates.size()==0)
            return ans;
        vector<int> temp;
        solve(ans, temp, 0, target, candidates);
        return ans;
    }
};