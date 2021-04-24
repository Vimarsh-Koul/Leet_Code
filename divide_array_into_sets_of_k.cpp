class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        if(nums.size()%k!=0)
            return false;
        
        if(k> nums.size())
            return false;
        
        map<int,int> m;
        
        for(auto it: nums)
            m[it]++;
        
        while(true){
            int count = k;
            bool first = true;
            int prev=0;
            if(m.size()==0)
                return true;
            
            for(auto it: m){
                
                if(count == 0)
                    break;
                
                int curr = it.first;
                if(first){
                    first = false;
                    if(it.second==1){
                        m.erase(it.first);
                    }
                    else
                        m[it.first]--;
                    count--;
                }
                
                else if(curr==prev+1){
                    if(m[it.first]==1){
                        m.erase(it.first);
                    }
                    
                    else
                        m[it.first]--;
                    count--;
                }
                
                else if(curr!= prev+1){
                    cout<<it.first-1<<endl;
                    return false;
                }
                prev=it.first; 
            }
            
            if(m.size()==0 && count>0)
                return false;
        }
        
        return true;
    }
};