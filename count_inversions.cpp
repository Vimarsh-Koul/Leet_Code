long long int ans;

void sort(long long int arr[], long long int start, long long int end){
    
    // cout<<"inside sort"<<endl;
    
    long long int i = start;
    long long int mid = (start + end)/2;
    long long int j = mid +1;
    vector<long long int> v;
    long long int val = 0;
    long long int temp = 0;
    
    while(i<=mid and j<=end){
        
        if(arr[i] > arr[j]){
            temp++;
            v.push_back(arr[j]);
            j++;
        }
        
        else{
            val= val + temp;
            v.push_back(arr[i]);
            i++;
        }
        
    }
    
    while(i<=mid){
        val+=temp;
        v.push_back(arr[i++]);
    }
    
    while(j<=end)
    v.push_back(arr[j++]);
    
    long long int k = 0;
    for(long long int i=start;i<=end;i++){
        arr[i] = v[k++];
        // cout<<arr[i]<<endl;
    }
    // cout<<val<<endl;
    ans += val;
    return;
    
}

void merge(long long int arr[], long long int start, long long int end){
    // cout<<"inside Merge"<<endl;
    if(start>=end)
        return;
        
    long long int mid = (start + end)/2;
        
    merge(arr,start,mid);
    merge(arr,mid+1, end);
    sort(arr, start, end);
    return;
}
    
    
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        ans  = 0;
        merge(arr,0,N-1);
        return ans;
    }

};
