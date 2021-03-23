class Solution {
public:
    bool isHappy(int n) {
        
        if(n==1)
            return true;

        unordered_map<int,bool> map;
        
        while(true){
            
            if(n==1)
                return true;

            
            if(map.find(n)!=map.end())
                return false;
            
            map[n]=true;
            
            int temp=0;
            while(n>0){
                int num = n%10;
                temp+=(num*num);
                n=n/10;
            }
            n = temp;
        }
    }
};