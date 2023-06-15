class info{
    public:
        char ch;
        int count;

        info(char c, int d){
            ch = c;
            count = d;
        }
};

class compare{
    public:
        bool operator()(info* a, info* b){
            return a->count < b->count;
        }
};


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        //create a max heap
        priority_queue<info*, vector<info*>, compare > maxHeap;

        if(a > 0){
            info* temp = new info('a', a);
            maxHeap.push(temp);
        }
        if(b > 0){
            info* temp = new info('b', b);
            maxHeap.push(temp);
        }
        if(c > 0){
            info* temp = new info('c', c);
            maxHeap.push(temp);
        }

        string ans = "";

        while(maxHeap.size() > 1){

            info* first = maxHeap.top();
            maxHeap.pop();
            info* second = maxHeap.top();
            maxHeap.pop();

            //check if we can insert 2 characters of first 
            if(first->count >= 2){
                ans+=first->ch;
                ans+=first->ch;

                first->count -= 2;

            }else{
                ans+=first->ch;
                first->count -= 1;
            }

            // check if we can insert 2 characters of second and if second count is greater tha first
            if(second->count >= 2 && second->count >= first->count){
                ans+=second->ch;
                ans+=second->ch;
                second->count -= 2;
            }
            else{
                ans+=second->ch;
                second->count -= 1;  
            }

            //check if count is greater than 0 -> insert back to heap
            if(first->count > 0){
                info* temp = new info(first->ch, first->count);
                maxHeap.push(temp);
            }
            if(second->count > 0)
                maxHeap.push(new info(second->ch, second->count));
        }

        if(maxHeap.size() == 1){
            info* temp = maxHeap.top();
            maxHeap.pop();

            if(temp->count >= 2){
                ans+=temp->ch;
                ans+=temp->ch;

                temp->count -= 2;

            }else{
                ans+=temp->ch;
                temp->count -= 1;
            }
            
        }

        return ans;

    }
};