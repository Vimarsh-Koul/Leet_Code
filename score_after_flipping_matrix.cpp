class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
       for(int i=0;i<A.size();i++){
           if(A[i][0]==0){
               for(int j=0;j<A[i].size();j++){
                   if(A[i][j]==0)
                       A[i][j]=1;
                   else
                       A[i][j]=0;
               }
           }
       }
        
        for(int i=0;i<A[0].size();i++){
            int zero, one;
            zero=one=0;
            
            for(int j=0;j<A.size();j++){
                if(A[j][i]==0)
                    zero++;
                else
                    one++;
            }
            
            if(one< zero){
              for(int j=0;j<A.size();j++){
                if(A[j][i]==0)
                    A[j][i]=1;
                else
                    A[j][i]=0;
                }  
            }
        }
        
        int ans =0;
        
        for(int i=0;i<A.size();i++){
            int siz = A[i].size()-1;
            
            for(int j =0;j<A[i].size();j++){
                ans+= A[i][j]* (1<<siz);
                siz--;
            }
        }
        
        return ans;
    }
};