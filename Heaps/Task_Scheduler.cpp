


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        //store the counts of all the character in an array;
        int freq[26] = {0};
        int s = tasks.size();
        
        for(int i=0; i<s; i++){
            int index = tasks[i] - 'A';
            freq[index]++;
        }

        //max heap
        priority_queue<int> maxHeap;

        // insert all the tasks with the cooldowns and the counts
        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                maxHeap.push(freq[i]);
            }
        }

        int ans=0;

        while(!maxHeap.empty()){
            vector<int> remain;
            int cycle = n+1;

            while(cycle && !maxHeap.empty()){
                int top = maxHeap.top();
                maxHeap.pop();

                if(top > 1){
                    remain.push_back(top - 1);
                }

                cycle--;
                ans++;
            }

            for(int i: remain){
                maxHeap.push(i);
            }

            if(maxHeap.empty()) break;

            ans+=cycle;
        }

        return ans;


    }
};