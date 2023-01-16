class Solution{
    public:
    
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        
        if(leftChild < n && arr[largest] < arr[leftChild]){
            largest = leftChild;;
        }
        
        if(rightChild < n && arr[largest] < arr[rightChild]){
            largest = rightChild;;
        }
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr,n,largest);
        }
        
    }
    
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> ans;
        
        //step 1: merge both arrays into one
        for(auto i:a){
            ans.push_back(i);
        }
        
        for(auto i:b){
            ans.push_back(i);
        }
        
        // build heap using merged array
        
        int size= ans.size();
        
        for(int i=size/2-1 ; i>=0; i--){
            heapify(ans, size, i);
        }
    
        return ans;
    }
};