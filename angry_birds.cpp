bool check(vector<int> &pos, int mid, int birds){
    
    int bird = 1;
    int  current = 0;
    
    for(int i=1;i<pos.size();i++){
        
        if(pos[i] - pos[current] >= mid){
            bird++;
            current = i;
        }
           
        
        if(bird==birds)
            return true;
    }
    return false;
}


class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        
        
        int start = 1;
        int end = pos[pos.size()-1];
        int ans = 0;
        
        while(start <= end){
    
            int mid = (start + end)/2;   
            bool flag = check(pos, mid, m);

            if(flag){
                ans = mid;
                start = mid + 1;
            }
            
            else
                end = mid - 1; 
        }
        
        return ans;
    }
};