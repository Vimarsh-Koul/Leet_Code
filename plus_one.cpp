class Solution {
public:
    vector<int> plusOne(vector<int>& ls) {

        
        int carry = 0;
        int ele = ls[ls.size()-1];
        ele = ele + 1;
        ls[ls.size()-1] = ele%10;
        carry = ele/10;
        
        int i = ls.size()-2;
        while(carry>0 && i>=0){
            ele = ls[i];
            ele+=(carry);
            ls[i]=ele%10;
            carry = ele/10;
            i--;
        }
        vector<int> ans;
        if(carry>0)
            ans.push_back(carry);
        
        for(auto it: ls)
            ans.push_back(it);
        
        
        return ans;
    }
};