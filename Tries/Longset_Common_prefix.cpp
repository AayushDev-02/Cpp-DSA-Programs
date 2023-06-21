class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";

        string x = strs[0];

        for(int i=0; i<x.length(); i++){
            char ch = x[i];

            for(int j=0; j<strs.size(); j++){
                if( strs[j].size() < i || strs[j][i] != ch){
                    return ans;
                }
            }
            ans+=ch;
        }

        return ans;
    }
};


//2nd approach
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

    void findLCP(Node* root, string first, string &ans){
        
        if(root->isTerminal) return;

        for(int i=0; i<first.length(); i++){
            char ch = first[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                int index = ch-'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal){
                break;
            }

        }

    }

    string longestCommonPrefix(vector<string>& strs) {
        Node* root = new Node('-');
        
        for(int i=0; i<strs.size(); i++){
            insertInTrie(root, strs[i]);
        }

        string ans = "";
        string first =strs[0];

        findLCP(root, first, ans);
        return ans;

    }
};