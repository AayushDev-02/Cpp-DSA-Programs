class info{
    public:
        int n1;
        int n2;
        int sum;

        info(int x, int y, int add){
            n1 = x;
            n2 = y;
            sum = add;
        }
};

class compare{
    public:
        bool operator()(info* a, info* b){
            return a->sum > b->sum;
        }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<info*, vector<info*>, compare> minHeap;

        for(int i=0; i<nums1.size(); i++){
                info* temp = new info(i, 0, nums1[i] + nums2[0]);
                minHeap.push(temp);

        }

        vector<vector<int>> ans;


        while( !minHeap.empty() && k--){
            info* topNode = minHeap.top();
            int index1 = topNode->n1;
            int index2 = topNode->n2;
            minHeap.pop();
            vector<int> temp;

            temp.push_back(nums1[index1]);
            temp.push_back(nums2[index2]);

            ans.push_back(temp);

            if(index2 + 1 < nums2.size()){
                info* newNode = new info(index1, index2 + 1, nums1[index1] + nums2[index2 + 1]);
                minHeap.push(newNode);
            }
        }

        return ans;
    }
};