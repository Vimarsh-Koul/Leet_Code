int len(vector<int> &nums, int x){
    unordered_map<int,int> map;
    int sum=0, maxlen =0;
    
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        map[sum] = i;
    }
    
    if(x> sum)
        return -1;
    
    map[0] = 0;
    
    sum -= x;
    int val =0;
    for(int i=0;i<nums.size();i++){
        val += nums[i];
        
        if(map.find(val-sum)!=map.end()){
            
            if(val-sum)
                maxlen = max(maxlen, i-map[val-sum]);
            
            else
                maxlen = max(maxlen, i+1);
        }
    }
    
    return (maxlen == 0) ? (sum == 0 ? nums.size() : -1) : nums.size()-maxlen;
    
    // return maxlen;
}


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       return len(nums, x);
    }
};