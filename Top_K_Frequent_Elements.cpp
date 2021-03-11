class Solution {
public:
    
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
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto it:nums)
            map[it]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,compare> q(map.begin(),map.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};