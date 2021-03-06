#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int bit = (1<<s.length());
    // cout<<bit<<endl;
    for(int i=1;i<bit;i++){
        string temp="";
        int count=0;
        int k= s.length()-1;
        for(int j=0;j<s.length();j++){
            // cout<<(1<<k)<<endl;
            if((i & (1<<k))==0){
                if(count>0)
                temp+=to_string(count);
            temp+=s[j];
            count=0;
            }
            else
            count++;
            k--;
        }
        
        if(count>0)
        temp+=to_string(count);
        cout<<temp<<endl;
    }
    
}