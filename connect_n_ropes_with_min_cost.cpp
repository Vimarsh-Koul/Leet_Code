long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue<long long,vector<long long>,greater<long long>> q;
    long long sum =0;
    vector<long long> temp;
    for(long long i=0;i<n;i++)
        q.push(arr[i]);
    
    long long t0,t1;
    
    while(q.size()!=1){
        t0 = q.top();q.pop();
        t1 = q.top();q.pop();
        // if(first){
        //   sum+= t0+t1;
        //   first=false;
        // }
       
        // cout<<t0<<" "<<t1<<endl;
        q.push(t0+t1);
        temp.push_back(t0+t1);
    }
    
    for(auto it: temp)
    sum+=it;
    
    return sum;
}