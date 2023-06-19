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
}

//insertion in trie
void insertWord(Node* root, string s){  //we will use recursion - we will only insert single character , baaki recursion sambhalega

    //base case
    if(word.length() == 0){
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


    insertWord(child, word.substr(1));
    
}

int main(){

    //creating a new trie
    Node* root = new Node('-');

    insertWord(root, coding);


}