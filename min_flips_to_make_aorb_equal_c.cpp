class Solution {
public:
    int minFlips(int a, int b, int c) {
        int bit= max(a,b);
        bit=max(bit,c);
        // cout<<bit<<endl;
         bit = log2(bit)+1;
        int count =0;
        cout<<bit<<endl;
        for(int i=0;i<bit;i++){
            int temp = 1<<i;
            int checka = a&temp;
            int checkb = b&temp;
            int checkc = c&temp;
            if((checka|checkb) != checkc){
                if(checkc==0){
                    if(checka!=0 && checkb!=0)
                        count+=2;
                    else
                        count+=1;
                }
                   
                else
                    count+=1;
            }
        }
        return count;
    }
};