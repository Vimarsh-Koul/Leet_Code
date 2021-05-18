class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxlen = 0;
        for(int i=1;i<arr.size()-1;){
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
                int len = 1;
                int index = i-1;
                while(index>=0 and arr[index] < arr[index+1]){
                    len++;
                    index--;
                }
                
                while(i< arr.size()-1 and arr[i] > arr[i+1]){
                    len++;
                    i++;
                }
                
                maxlen = max(len, maxlen);
            }
            
            else
                i++;
        }
        
        return maxlen;
    }
};




int solve(vector<int> &arr, int index){
    int count = 1;
    
    int i= index -1;
    int j = index + 1;
   
   while(i>=0){
       if(arr[i] < arr[i+1]){
           count++;
           i--;
       }
       
       else
           break;
   } 
    
    while(j < arr.size()){
        if(arr[j] < arr[j-1]){
            count++;
            j++;
        }
        
        else
            break;
    }
    
    return count;
}


class Solution {
public:
    int longestMountain(vector<int>& arr) {
        vector<int> peaks;
        
        for(int i=1;i<arr.size()-1;i++)
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1])
                peaks.push_back(i);
        
        int maxlen = 0;
        for(auto it: peaks){
           int len = solve(arr, it);
            maxlen = max(maxlen, len);
        }
        
        return maxlen;
    }
};