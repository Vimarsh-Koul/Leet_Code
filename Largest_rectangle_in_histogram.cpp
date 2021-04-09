class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int right[heights.size()];
        int left[heights.size()];
        
        right[heights.size()-1]= heights.size();
        stack<int> s;
        s.push(heights.size()-1);
        for(int i= heights.size()-2;i>=0;i--){
            while(s.size()> 0 && heights[s.top()]>=heights[i])
                s.pop();
            
            if(s.size()==0)
                right[i] = heights.size();
            else 
                right[i] = s.top();
            
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        left[0] = -1;
        s.push(0);
        
        for(int i=1;i<heights.size();i++){
            while(s.size()>0 && heights[i]<= heights[s.top()])
                s.pop();
            
            if(s.size()==0)
                left[i] = -1;
            else
                left[i] = s.top();
            s.push(i);
        }
        
        int maxh = 0;
        for(int i=0;i<heights.size();i++)
           maxh = max(maxh, (right[i]-left[i]-1)*heights[i]);

        return maxh;
    }
};