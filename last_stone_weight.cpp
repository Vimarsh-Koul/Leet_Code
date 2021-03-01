class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];
        
        priority_queue<int> q;
        for(auto it: stones)
            q.push(it);
        
        int t0, t1,sum;
        
        while(q.size()>1){
            t0 = q.top();
            q.pop();
            t1 = q.top();
            q.pop();
            sum = abs(t0-t1);
            if(sum!=0)
                q.push(sum);
        }
        if(q.size()==0)
            return 0;
        return q.top();
    }
};