class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
        multiset<int> set(a.begin(), a.end());
        
       for(int i=0;i<b.size(); i++){
           auto ele = set.upper_bound(b[i]);
           if(ele==set.end())
               ele = set.begin();
           
           a[i] = *ele;
           set.erase(ele);
       }
        
        return a;
    }
};