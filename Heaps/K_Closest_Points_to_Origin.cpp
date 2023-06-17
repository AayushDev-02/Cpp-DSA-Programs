class info{
    public: 
        int sum;
        int index;
        info(int s, int i ){
            sum = s;
            index = i;
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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<info*, vector<info*>, compare> minHeap;

        for(int i=0; i<points.size(); i++){
            
            int sum = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            int index = i;

            info* newNode = new info(sum, index);
            minHeap.push(newNode);
        }
        vector<vector<int>> ans;
        while(k--){
            info* topNode = minHeap.top();
            minHeap.pop();
            int index = topNode->index;
            ans.push_back(points[index]);
        }

        return ans;
    }
};