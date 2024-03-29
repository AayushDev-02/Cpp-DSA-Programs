long long minCost(long long arr[], long long n) {
        
        long long ans=0;
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        
        for(long long i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            long long sum = a+b;
            ans+=sum;
            
            pq.push(sum);
        }
        
        return ans;
    }