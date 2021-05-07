class Solution {
public:
    int maxValue(int n, int index, int maxsum) {
                long long int l = index;
        long long int r = n - index -1;
        long long int res =0;
        long long int low = 1;
        long long int high = maxsum;
        
        while(low<=high){
            long long int mid = low + (high - low)/2;
            
            long long int m = mid -1;
            
            long long int ls, rs;
            ls = rs =0;
            
            if(l<=m){
                ls = (m*(m+1))/2 - ((m-l)*(m-l+1))/2;
            }
            
            else{
                ls = (m*(m+1))/2 + 1*(l - m);
            }
            
            if(r<=m){
                rs = (m*(m+1))/2 - ((m-r)*(m-r+1))/2;
            }
            else{
                rs = (m*(m+1))/2 + 1*(r - m);
            }
            
            long long int sum = ls+rs + mid;
            
            if(sum<=maxsum){
                res = mid;
                low = mid +1;
            }
            
            else{
                high = mid -1;
            }
        }
        
        return res;
    }
};