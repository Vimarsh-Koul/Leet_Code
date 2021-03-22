class Solution {
public:
    int titleToNumber(string c) {
        long long int sum =0;
        
        for(int i=0;i<c.length();i++){
            sum+=pow(26, c.length()-i-1)*(c[i]-64);
        }
        
        return sum;
    }
};