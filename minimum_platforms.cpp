class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i=1,j=0;
    	
    	int maxs = 1;
    	int s =1;
    	
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        s++;
    	        i++;
    	    }
    	    
    	    else if(arr[i]> dep[j]){
    	        s--;
    	        j++;
    	    }
    	    
    	    maxs = max(maxs, s);
    	}
    	
    	return maxs;
    }
};