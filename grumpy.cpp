class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int correct = 0;
        int grumpytillnow  =0;
        int maxgrumpy=0;
        
        for(int i=0;i<customers.size(); i++){
            
            correct += (grumpy[i]) ? 0 : customers[i];
            grumpytillnow += (grumpy[i]) ? customers[i] : 0;
            
            if( i>=minutes and grumpy[i-minutes])
                grumpytillnow -= customers[i-minutes];
            
            maxgrumpy = max(maxgrumpy, grumpytillnow);
            
        }
        
        return (correct + maxgrumpy);
    }
};