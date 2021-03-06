#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    int res =0;
    while(n!=1){
        if(n%2==0)
        n/=2;
        else if(n==3){
            res+=2;
            break;
        }
        
        else if(n%4 ==1)
        n-=1;
        else if(n%4 == 3)
        n+=1;
        res++;
    }
    
    cout<<res<<endl;
}