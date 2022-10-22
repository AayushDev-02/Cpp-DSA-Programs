#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        
        int ch=65;
        while(j<=i){
            cout<<char(ch+i-1);
            j++;
            ch++;

        }
        cout<<endl;
        i++;
    }


    return 0;
}