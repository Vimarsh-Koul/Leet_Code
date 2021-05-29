void solve(vector<char> &box, int n){
    
    int i,j;
    i=j=0;
    
    while(i<n and j<n){
        
        if(box[j]=='#')
            j++;
        
        else if(box[j]=='.'){
            swap(box[i], box[j]);
            i++;
            j++;
        }
        
        else if(box[j]=='*'){
            j++;
            i=j;
        }
        
    }
    
}

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        for(int i=0;i<box.size();i++){
            solve(box[i], box[i].size());
        }
        cout<<box[0].size()<<" "<<box.size()<<endl;
        vector<vector<char>> mat(box[0].size(), vector<char> (box.size(), '@'));
        
       for(int j=0;j<box[0].size();j++){
        
           for(int i=box.size()-1;i>=0;i--){
               mat[j][box.size()-i-1] = box[i][j];
           }
           
       }
        
        return mat;
    }
};