#include <iostream>
using namespace std;

int get_length(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;    
    }
    return count;
}



int main(){

    char name[20];
    cout<<"Enter your name: "<<endl;
    cin>>name;
 
    int length = get_length(name);

    cout<<"Your name is: "<<name<<endl;
    cout<<"Length is "<<length<<endl;

    return 0; 
}