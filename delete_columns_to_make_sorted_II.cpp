class Solution {
public:
    int minDeletionSize(vector<string>& str) {
       int res =0;
        unordered_set<int> s;
        
        for(int i=1;i<str.size();i++){
            for(int j=0;j<str[i].size();j++){
                cout<<str[i].size()<<" "<<j<<" ";
                 cout<<str[i-1][j]<<" "<<str[i][j]<<endl;
                if(s.count(j)>0 || str[i-1][j]==str[i][j])
                    continue;
                
                if(str[i-1][j] > str[i][j]){
                    cout<<"shit "<<endl;
                    cout<<str[i-1][j]<<" "<<str[i][j]<<endl;
                    s.insert(j);
                    i=0;
                }
                break;
            }
        }
        
        for(auto it=s.begin(); it!=s.end(); it++)
            cout<<*it<<endl;
        
        return s.size();
    }   
};