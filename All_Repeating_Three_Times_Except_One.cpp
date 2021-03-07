#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    
    int t,tp1,tp2;
    t = INT_MAX;
    tp1=tp2= 0;
    for(auto it: v){
        int t3 = t & it;
        int t3p1 = tp1 & it;
        int t3p2 = tp2 & it;
        t^= t3;
        tp1^=t3p1;
        tp2^=t3p2;
        
        t|= t3p2;
        tp1|= t3;
        tp2|= t3p1;
    }
    
    cout<<tp1<<endl;
}