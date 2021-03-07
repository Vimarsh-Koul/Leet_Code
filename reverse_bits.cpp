class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0;
        int size = 31;
        
        while(n>0){
            if(n&1)
                num|=1<<size;
            n>>=1;
            size--;
        }
        return num;
    }
};