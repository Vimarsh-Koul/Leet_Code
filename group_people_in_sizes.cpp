class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        vector<vector<int>> ans(group.size());
        
        if(group.size()==0)
            return ans;
        
        for(int i=0;i<group.size();i++){
            ans[group[i]-1].push_back(i);
        }
        
        vector<vector<int>> realans;
        
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()>0){
                if(ans[i].size()<=(i+1))
                    realans.push_back(ans[i]);
                
                else{
                    int realsize = ans[i].size();
                    vector<int> temp;
                    for(int j =0; j<realsize;j++){
                        if((j+1)%(i+1)==0){
                            temp.push_back(ans[i][j]);
                            realans.push_back(temp);
                            temp.clear();
                            continue;
                        }
                        temp.push_back(ans[i][j]);
                    }
                    if(temp.size()>0)
                        realans.push_back(temp);
                }
            }
        }
        return realans;
    }
};