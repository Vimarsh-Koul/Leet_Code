class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
        if(nums.size()==1)
            return 1;
        
        
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        prefix[1] = nums[1];
        
        int ans =0;
        
        for(int i=2;i<nums.size();i+=2)
            prefix[i] = prefix[i-2]+ nums[i];
        
        for(int i=3;i<nums.size();i+=2)
            prefix[i] = prefix[i-2] + nums[i];
        
        int even,odd;
        if(prefix.size()%2==0){
            even = prefix[prefix.size()-2];
            odd = prefix[prefix.size()-1];
        }
        
        else{
            even = prefix[prefix.size()-1];
            odd = prefix[prefix.size()-2];
        }
        
        for(int i=0;i<nums.size(); i++){
            if(i%2==0){
                int evensum = odd;
                if(i-1>=0)
                    evensum-= prefix[i-1];
                if(i-2>=0)
                    evensum+= prefix[i-2];
                
                int oddsum = even - nums[i];
                if(i-1>=0)
                    oddsum += prefix[i-1];
                
                if(i-2>=0)
                    oddsum -= prefix[i-2];

                if(oddsum==evensum)
                    ans++;
                
            }
            
            else{
                int oddsum = even;
                
                if(i-1>=0)
                    oddsum-= prefix[i-1];
                
                if(i-2>=0)
                    oddsum += prefix[i-2];
                
                int evensum = odd - nums[i];
                
                if(i-1>=0)
                    evensum += prefix[i-1];
                
                if(i-2>=0)
                    evensum -= prefix[i-2];

                if(oddsum==evensum)
                    ans++;
            }
        }
        
        return ans;
    }
};