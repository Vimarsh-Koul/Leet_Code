bool gre(int a, int b){
        return a > b;
    }
    
class Solution
{
public:

    vector<int> candyStore(int candies[], int n, int k)
    {
        vector<int> great(candies, candies+n);
        vector<int> small(candies, candies+n);
        
        
        sort(great.begin(), great.end(), gre);
        sort(small.begin(), small.end());
        
        int count0, count1;
        count0 = count1 = 0;
        
        int i,j;
        i =0;
        j = n-1;
        
        while(i<=j){
            count0 += small[i];
            count1 += great[i];
            i++;
            j-= k;
        }
        
        vector<int> ans = {count0, count1};
        return ans;
        
    }
};