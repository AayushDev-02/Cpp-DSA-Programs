class Node{
    public:
        char ch;
        Node* children[26];
        bool isTerminal;
        int childCount;

        Node(char ch){
            this->ch = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            this->childCount = 0;
            this->isTerminal=false;
        }

};


class Solution {
public:

    void insertInTrie(Node* root, string s){
        if(s.length() == 0){
            root->isTerminal = true;
            return;
        }

        char ch = s[0];
        int index = ch - 'a';
        Node* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new Node(ch);
            root->childCount++;
            root->children[index] = child;
        }

            insertInTrie(child, s.substr(1));
    }

    void storeSuggestions(Node* curr, vector<string> &temp, string &prefix){        

        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        //a-z tak choices de do
        for(int i=0; i<26; i++){
            
            Node* next = curr->children[i];

            if(next != NULL){
                //if child exists
                prefix.push_back(i+'a');
                //baaki recursion sambhalega
                storeSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }

    }

    vector<vector<string>> getSuggestions(Node* root, string searchWord){

        Node* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        //traverse the input string
        for(int i=0; i<searchWord.length(); i++){
            
            char lastChar = searchWord[i];

            int index = lastChar - 'a';
            Node* curr = prev->children[index];

            //check if curr is not null
            if(curr == NULL){
                break;
            }else{
                //iske andar mai saare suggestions store karke launga
                vector<string> temp;
                prefix.push_back(lastChar);
                storeSuggestions(curr, temp, prefix);
                output.push_back(temp);

                prev = curr;
            }
        }

        return output;

    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Node* root = new Node('-');

        for(int i=0; i<products.size(); i++){
            insertInTrie(root, products[i]);
        }

        vector<vector<string>> ans = getSuggestions(root, searchWord);

        return ans;

    }
};