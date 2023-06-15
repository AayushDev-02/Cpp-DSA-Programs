class info{
    public:
        char ch;
        int count;

        info(char c, int o){
            ch = c;
            count = o;
        }
};

class compare{
    public:
        bool operator()(info a, info b){
            return a.count < b.count;
        }
};

class Solution {
public:
    string reorganizeString(string s) {

        //create mapping
        int freq[26] = {0};
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            freq[ch-'a']++;
        }

        priority_queue<info, vector<info>, compare> maxHeap;

        //pushing the map entries into the heap
        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                info temp(i+'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans= "";

        while(maxHeap.size() > 1){
            info first = maxHeap.top();
            maxHeap.pop();
            

            info second = maxHeap.top();
            maxHeap.pop();
            

           
                ans += first.ch;
                ans += second.ch;

                first.count--;
                second.count--;

                if(first.count != 0){
                   
                    maxHeap.push(first);
                }

                if(second.count != 0){
                    
                    maxHeap.push(second);
                }
        }

        

        if(maxHeap.size() == 1){
            info temp = maxHeap.top();
            maxHeap.pop();
            if(temp.count == 1){
                ans+=temp.ch;
            }
            else{
                return "";
            }
        }

        return ans;

        

    }
};