class Solution {
public:
    
    int solve(string s, int k, int start, int end){
        
        if(start==end)
            return 0; 
           
        
        if(k>end)
            return 0;
        
        unordered_map<char,int> map;
        
        for(int i=start;i<end;i++)
            map[s[i]]++;
        
        for(int mid = start;mid<end;mid++){
            if(map[s[mid]]>=k) continue;
            
            int index = mid+1;
            while(index<end && map[s[index]]<k) index++;
            
            return max(solve(s, k, start, mid), solve(s, k, index, end));
        }
        
        return end-start;
    }
    
    int longestSubstring(string s, int k) {
        return solve(s, k, 0, s.length());
    }
};