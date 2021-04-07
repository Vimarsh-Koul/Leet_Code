//  sort method

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        int start, end;
        start = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=temp[i] && start==-1)
                start = i;
            
            else if(nums[i]!= temp[i] && start!=-1)
                end = i;
        }
        if(start==-1)
            return 0;
        
        return end - start +1;
    }
};

// using stack

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int leftsmall = nums.size();
        for(int i=0;i<nums.size();i++){
            while(!s.empty() && nums[s.top()]> nums[i]){
                leftsmall = min(leftsmall, s.top());
                s.pop();
            }
            s.push(i);
        }
        // s.clear();
        while(!s.empty())
            s.pop();
        
        int rightbig = 0;
        for(int i=nums.size()-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]< nums[i]){
                rightbig = max(rightbig, s.top());
                s.pop();
            }
            s.push(i);
        }
        
        return (rightbig-leftsmall) > 0 ? rightbig - leftsmall +1 : 0;
    }
};

// using simple traversal

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int lefts = INT_MAX;
        bool flag = false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])
                flag = true;
            
            if(flag)
                lefts = min(lefts, nums[i]);
        }
        
        flag = false;
        int rights = INT_MIN;
        for(int i= nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1])
                flag = true;
            if(flag)
                rights = max(rights, nums[i]);
        }
        
        int l,r;
        l=r=-1;
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]>lefts){
                l = i;
                break;
            }
        
        for(int i=nums.size()-1;i>=0;i--)
            if(nums[i]<rights){
                r= i;
                break;
            }
        
        return (r-l)>0 ? r-l+1: 0;
    }
};

