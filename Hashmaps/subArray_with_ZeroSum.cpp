 bool subArrayExists(int arr[], int n)
    {
        
        int sum = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        
        for(int i=0; i<n; i++){
            sum+= arr[i];
            
            if(m.find(sum) != m.end()){
                return true;
            }
            
            m[sum]++;
        }
        
        return false;
        
    }