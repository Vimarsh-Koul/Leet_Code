class Solution{
    public:
    // Function to find the subarray with given sum k
    // arr: input array
    // n: size of array
    vector<int> subarraySum(int arr[], int n, int s){
        
      int i=0, j =0;
      int sum =arr[0];
      vector<int> ans;
      while(i< n && j<n){
          if(sum == s){
              ans.push_back(i+1);
              ans.push_back(j+1);s
              return ans;
          }
          
          if(sum< s){
              j++;
              sum+=arr[j];
          }
          
          else if(sum> s){
              sum-= arr[i];
             i++; 
          }

      }
      
    ans.push_back(-1);
    return ans;
        
    }
};