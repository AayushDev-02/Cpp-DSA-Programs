#include <iostream>
using namespace std;


class Node {
    public : 
        char data;  //stores the char values
        Node* children[26];
        bool isTerminal;

        Node(char data){
            this->data = data;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }

            this->isTerminal = false;
        }
};

void insertWord(Node* root, string s){

    //base case
    if(s.length() == 0){
        root->isTerminal = true;
        return 0;
    }


    char ch = s[0];
    int index = ch - 'A';

    Node* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        child = new Node(ch);
        root->children[index] = child;
    }

    insertWord(child, s.substr(1));
}

int main(){



    return 0;
}