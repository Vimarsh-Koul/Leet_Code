#define ll long long int
#define mod (long long int)1e9+7
bool vec(int a, int b){
    return a > b;
}

class Solution {
public:
    ll res = 0;
    int maxProfit(vector<int>& in, int orders) {
        ll n = in.size();
        sort(in.begin(), in.end(), vec);
        
        for(int i=0;i<in.size();i++){
            ll diff = in[i] - ((i==in.size()-1) ? 0 : in[i+1]);
            
            ll x = min((ll)orders, (i+1)*diff);
            
            ll right = in[i];
            ll left = right - (x)/ (i+1);
            res += (((right)*(right+1))/2 - ((left)*(left+1))/2)*(i+1);
            res %= mod;
            
            res += left*(x%(i+1));
            res %= mod;
            orders -= x;
        }
        return res;
    }
};