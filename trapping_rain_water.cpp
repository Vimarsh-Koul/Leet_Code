class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size()==0)
            return 0;
        
        int maxl[height.size()];
        int maxr[height.size()];
        
        maxl[0]=height[0];
        for(int i=1;i<height.size();i++){
            maxl[i]=max(maxl[i-1], height[i]);
        }
        maxr[height.size()-1]= height[height.size()-1];
        
        for(int i=height.size()-2;i>=0;i--){
            maxr[i]= max(maxr[i+1], height[i]);
        }
        
        int out =0;
        
        for(int i=0;i<height.size();i++){
            out+= min(maxl[i], maxr[i]) - height[i];
        }
        
        return out;
    }
};