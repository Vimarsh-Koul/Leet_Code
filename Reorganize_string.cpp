struct compare {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // if frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;
 
        // insert elements in the priority queue on the basis of
        // decreasing order of frequencies
        return p1.second < p2.second;
    }
};


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> map;
        // for(auto it: s)
        //     map[it]++;
        
        for(int i=0;i<s.length();i++)
            map[s[i]]++;
        
        for(auto it: map)
            cout<<it.first<<" "<<it.second<<endl;
        
         priority_queue<pair<char, int>, vector<pair<char, int> >,compare> q(map.begin(), map.end());
        string temp="";
        while(q.size()>1){
            char s0 = q.top().first;q.pop();
            char s1 = q.top().first;q.pop();
            temp+=s0;
            temp+= s1;
            map[s0]--;
            map[s1]--;
            
            // cout<<map[s0]<<" "<<map[s1]<<endl;
            if(map[s0]!=0){
                // cout<<map[s0]<<" ";
                pair<char,int> p;
                p.first = s0;
                p.second = map[s0];
                q.push(p);
            }
            if(map[s1]!=0){
                // cout<<map[s1]<<endl;
                pair<char,int> p;
                p.first = s1;
                p.second = map[s1];
                q.push(p);
            }
            cout<<temp<<endl;
            
        }
        if(!q.empty()){
            int count = q.top().second;
            if(count>1)
                return "";
            temp+=q.top().first;
        }
        
        return temp;
    }
};