class Solution {
public:
    int totalMoney(int n) {
        int day = 1;
        int amount = 1;
        int monday = 1;
        int i=0;
        while(i<n-1){
            
            if(day%7==0 && day!=0){
                day = 0;
                monday++;
            }
            amount+= monday + day;
            day++;
            i++;
        }
        return amount;
    }
};