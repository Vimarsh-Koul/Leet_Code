    bool compare(string one, string two){
        string a = one+two;
        string b  = two+one;
        return a>=b;
    }

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        if(nums.size()==0)
            return "";
        
        bool flag = true;
        
        for(auto it: nums)
            if(it!=0){
                flag = false;
                break;
            }
        
        if(flag)
            return "0";
        
        vector<string> numsv;
        for(auto it: nums)
            numsv.push_back(to_string(it));
        
        sort(numsv.begin(),numsv.end(),compare);
        string ans="";
        for(auto it: numsv)
            ans+=it;
        
        return ans;
        
    }
};