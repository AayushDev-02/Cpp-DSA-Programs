#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ch=65;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<char(ch);
            j++;
        }
        cout<<endl;
        ch++;
        i++;

    }




    return 0;
}