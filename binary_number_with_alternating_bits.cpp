class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevbit;
        // (1<<0!=0)?1:0;
        // if(1<<0!=0)
        // currbit = 1;
        // else
        //     currbit =0;
        
        prevbit = n&1;
        
        n>>=1;
        int currbit;
        while(n>0){
            currbit = n&1;
            if(currbit!=prevbit){
                prevbit=currbit;
            }
            else if(currbit==prevbit)
                return false;
            n>>=1;
        }
        
        return true;
        
    }
};