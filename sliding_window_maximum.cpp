// using multiset 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int, greater<int>> set;
        if(nums.size()==0)
            return ans;
        
        for(int i=0;i<k;i++)
            set.insert(nums[i]);
        
        ans.push_back(*(set.begin()));
        
        for(int i=k;i<nums.size();i++){
           set.erase(set.find(nums[i-k]));
            
            set.insert(nums[i]);
            ans.push_back(*(set.begin()));
        }
        
        return ans;
    }
};


//  using priority queue or heap

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        if(nums.size()==0)
            return ans;
        
        for(int i=0;i<k;i++)
            pq.push(make_pair(nums[i], i));
        
        ans.push_back(pq.top().first);
        
        for(int i=k;i<nums.size();i++){
            while(pq.size() && pq.top().second<=(i-k))
                pq.pop();
            
            pq.push(make_pair(nums[i], i));
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};


// using dequeue

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size()==0)
            return ans;
        
        deque<pair<int,int>> dq;
        
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.front().second<=i-k)
                dq.pop_front();
            
            while(!dq.empty() && dq.back().first<nums[i])
                dq.pop_back();
            
            dq.push_back(make_pair(nums[i], i));
            if(i>=k-1)
                ans.push_back(dq.front().first);
        }
        
        return ans;
    }   
};





