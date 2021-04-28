class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        if(arr.size()==0 || arr.size()==1)
            return arr;
        
        int index =-1;
        
        for(int i = arr.size()-2;i>=0;i--){
            if(arr[i]> arr[i+1]){
                index = i;
                break;
            }
        }
        
        if(index == -1)
            return arr;
        
        int elei, elev;
        elei = elev = 0;
        
        for(int i= index+1;i<arr.size();i++){
            if(arr[i]< arr[index] && arr[i]> elev){
                elev = arr[i];
                elei = i;
            }
        }
        
        swap(arr[index], arr[elei]);
        return arr;
    }
};