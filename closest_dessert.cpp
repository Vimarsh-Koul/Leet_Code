class Solution {
public:
    
    void solve(vector<int> &base, int curr, vector<int> &ans, int index, int target){
        if(index == base.size() || (curr==target))
            return;

        ans.push_back(curr+ base[index]);
        ans.push_back(curr+ base[index]*2);

        if(curr==target || (curr+ base[index])==target || (curr + base[index]*2)==target)
            return;
        
        solve(base, curr, ans, index+1, target);
        solve(base, curr+ base[index], ans, index+1, target);
        solve(base, curr+ base[index]*2, ans, index+1, target);
        return;
    }
    
    
    int closestCost(vector<int>& base, vector<int>& topping, int target) {
        vector<int> ans;
        
        for(int i=0;i<base.size();i++){
            ans.push_back(base[i]);
            solve(topping, base[i], ans, 0, target);
        }
        
        int realans, diff;
        diff = INT_MAX;
        
        for(int i=0;i<ans.size();i++){
            int temp = abs(target- ans[i]);
            
            if(temp<diff){
                diff = temp;
                realans = ans[i];
            }
            
            if(temp==diff){
                if(ans[i]< realans)
                    realans = ans[i];
            }
        }
        
        return realans;
    }
};