class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int ma = INT_MIN;
        int mi;
        
        int i,j;
        i=0;
        j = height.size()-1;
        int times = height.size()-1;
        while(i!=j){
            mi = min(height[i],height[j])*times;
            ma = max(ma, mi);
            if(height[i]<height[j])
                i++;
            else
                j--;
            times--;
        }
        
        return ma;
    }
};