class Solution {
public:
    bool judgeCircle(string moves) {
        int lr,up;
        lr=up=0;
        
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L')
                lr++;
            else if(moves[i]=='R')
                lr--;
            
            else if(moves[i]=='U')
                up++;
            else if(moves[i]=='D')
                up--;
        }
    
    
    return (lr==0 && up==0);
     
    }
};