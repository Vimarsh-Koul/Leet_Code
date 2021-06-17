class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m){
            return kthElement(arr2, arr1, m, n, k);
        }
            
        
        int start = max(0,k-m);
        int end = min(k,n);
        
        while(start<=end){
            int mid = (start + end) >> 1;
            
            int cut2 = k - mid;
            
            int l1 = (mid==0) ? INT_MIN : arr1[mid-1];
            int l2 = (cut2==0) ? INT_MIN : arr2[cut2-1];
            
            int r1 = (mid==n) ? INT_MAX : arr1[mid];
            int r2 = (cut2==m) ? INT_MAX : arr2[cut2];
            
            if(l1<=r2 and l2<=r1)
                return max(l1,l2);
                
            else if(l1 > r2)
                end = mid - 1;
                
            else 
                start = mid + 1;
        }
        return -1;
    }
};