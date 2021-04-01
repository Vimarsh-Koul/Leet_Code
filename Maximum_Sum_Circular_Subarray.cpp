class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum=INT_MAX;
        
        bool flag = true;
        
        for(auto it: A){
            if(it>0)
                flag=false;
        }
        
        if(flag){
            int m = INT_MIN;
            for(auto it: A){
                if(it>m)
                    m = it;
            }
            
            return m;
        }
        
        int total =0;
        for(auto it: A)
            total+=it;
        
        int tempsum =0;
        for(int i=0;i<A.size();i++){
            tempsum+=A[i];
           sum = min(sum, tempsum);
            if(tempsum>0)
                tempsum =0;  
        }
        if(sum>0)
            return total; 
        
        int maxsum =0;
         tempsum =0;
        
        for(auto it:A){
            tempsum+= it;
            maxsum = max(maxsum, tempsum);
            if(tempsum<0)
                tempsum =0;
        }
 
        return max(maxsum,total-sum);
    }
};