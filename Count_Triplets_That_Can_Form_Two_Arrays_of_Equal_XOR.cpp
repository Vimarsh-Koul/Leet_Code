class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int c=0;
        if(arr.size()==0)
            return c;
        
        for(int i=0;i<arr.size()-1;i++){
            int x = arr[i];
            for(int j=i+1;j<arr.size();j++){
                x^=arr[j];
                if(x==0)
                    c+=j-i;
            }
        }
        
        return c;
    }
};