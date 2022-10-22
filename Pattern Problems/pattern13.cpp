#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    int ch=65;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<char(ch);
            j++;
            ch++;
        }
        cout<<endl;
        i++;
    }




    return 0;
}