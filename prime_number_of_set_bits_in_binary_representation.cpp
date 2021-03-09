class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        bool isprime[int(log2(r))+1+1];
        int n = int(log2(r))+1;
        memset(isprime,true,sizeof(isprime));
        isprime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]==true){
               for(int j = i*i;j<=n;j+=i)
                 isprime[j]=false; 
            }   
        }
        
        int count =0;
        for(int i=l;i<=r;i++){
            if(isprime[__builtin_popcount(i)])
                count++;
        }
        return count;
    }
};