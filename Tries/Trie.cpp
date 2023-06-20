#include <iostream>
#include <string>
using namespace std;

//creating trie
class Node{
    public:
        char data;
        //array of all the childern nodes
        Node* children[26]; // there can be maximum 26 childern , therefore an array of 26 nodes in dynamic allocation
        //a bool to store if the curr node is terminal
        bool isTerminal;

        //Constructor
        Node(char data){
            this->data = data;  //assigning the data  
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            this->isTerminal = false;   // default node is not a terminal
        }
};

//insertion in trie
void insertWord(Node* root, string s){  //we will use recursion - we will only insert single character , baaki recursion sambhalega

    //base case
    if(s.length() == 0){
        //set the last character as terminal
        root->isTerminal = true;
        return;
    }

    //find index
    char ch = s[0];
    int index = ch - 'A';

    //create a new child node
    Node* child;

    //check if child is already present at index
    if(root->children[index] != NULL ){ // when child is already present

        //set the child as the already present childern and then recursion will handle the rest
        child = root->children[index];

    }
    else{
        //create the child
        child = new Node(ch);
        root->children[index] = child;

    }


    insertWord(child, s.substr(1));
    
}

//searching in a trie
bool searchTrie(Node* root, string s){

    if(s.length() == 0){
        return root->isTerminal;
    }

    char ch = s[0];
    int index = ch - 'A';
    Node* child;

    //child already present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{   // not present
        return false;
    }

    return searchTrie(child, s.substr(1));
}

//Deletion in a trie
void deleteINTrie(Node* root, string s){
    if(s.length() == 0){
        root->isTerminal = false;
        return;
    }

    char ch = s[0];
    int index = ch - 'A';
    Node* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        cout << "String is not present in the trie" << endl;
        return ;
    }

    deleteINTrie(child, s.substr(1));
}

int main(){

    //creating a new trie
    Node* root = new Node('-');

    insertWord(root, "CODE");
    insertWord(root, "CODER");
    insertWord(root, "CODING");
    insertWord(root, "CODHELP");
    insertWord(root, "BABA");
    insertWord(root, "BABY");
    insertWord(root, "BABBAR");
    insertWord(root, "SHONA");

    bool ans = searchTrie(root, "SHONA");
    if(ans) cout << "Present" << endl;
    else cout << "Not Present" << endl;

    deleteINTrie(root, "SHONA");

    ans = searchTrie(root, "SHONA");
    if(ans) cout << "Present" << endl;
    else cout << "Not Present" << endl;

}




// USING TRIES: 

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
        
        //yaha mai galti karunga
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