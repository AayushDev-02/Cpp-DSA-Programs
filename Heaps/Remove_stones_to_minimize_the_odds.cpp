class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int i = 0;
        priority_queue<int> maxHeap;

        for(int i=0; i<piles.size(); i++){
            maxHeap.push(piles[i]);
        }

        
        while(k--){
            int topElement = maxHeap.top();
            maxHeap.pop();

            int val = topElement - floor(topElement/2);
            maxHeap.push(val);
        }

        int ans = 0;

        while(!maxHeap.empty()){
            int topElement = maxHeap.top();
            maxHeap.pop();
            ans += topElement;
        }

        return ans;
    
    }
};