bool sortbox(vector<int> &a, vector<int> &b){
    return a[1]> b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int trucksize) {
        sort(box.begin(), box.end(), sortbox);
        
        int ans = 0;
        
        for(int i=0;i<box.size();i++){
            
            if(trucksize==0)
                break;
            
           else if(trucksize >= box[i][0]){
                ans+= box[i][0]*box[i][1];
                trucksize-= box[i][0];
            }
            
            else if(trucksize < box[i][0]){
                ans += trucksize* box[i][1];
                trucksize =0;
            }
        }
        
        return ans;
    }
};