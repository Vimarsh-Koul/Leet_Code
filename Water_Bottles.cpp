class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        
        while(numBottles>= numExchange){
            int left = numBottles / numExchange;
            res+= left;
            numBottles = left + (numBottles%numExchange);
        }
        
        return res;
    }
};