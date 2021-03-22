class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int n = prices.size();
        int profit = 0;
        while(i<n-1){
            while(i<n-1 && prices[i]>=prices[i+1])
                i++;
            if(i==n-1)
                break;
            int buy =i;
            i++;
            while(i<n && prices[i]>=prices[i-1])
                i++;
            cout<<prices[buy]<<" "<<prices[i-1]<<endl;
            profit+= (prices[i-1]-prices[buy]);
        }
        
        return profit;
    }
};