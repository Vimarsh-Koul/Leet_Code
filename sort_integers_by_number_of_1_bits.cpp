class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int m = 0;
        unordered_map<int,vector<int>> map;
        for(auto it: arr){
            int pop = __builtin_popcount(it);
            if(it>m)
                m=it;
            map[pop].push_back(it);
        }
        
        for(auto &it: map){
            vector<int> temp = it.second;
            // sort(temp.begin(),temp.end());
            sort((it.second).begin(), (it.second).end());
        }
        
        for(auto it: map){
            cout<<it.first<<" ";
            for(auto temp: it.second)
                cout<<temp<<" ";
            cout<<endl;
        }
        
        vector<int> ans;
        for(int i=0;i<=log2(m);i++){
            vector<int> temp = map[i];
            for(auto it: temp)
                ans.push_back(it);
        }
        
        return ans;
    }
};