

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> ans = nums;
        sort(ans.begin(),ans.end(),greater<>());
        nums.clear();
        int n = ans.size();
        int i,j;
        i=0;
        j= n/2;
        while(i<n/2 && j<n){
            nums.push_back(ans[j]);
            nums.push_back(ans[i]);
            i++;j++;
        }
        
        if(j<n)
            nums.push_back(ans[j]);
    }
};