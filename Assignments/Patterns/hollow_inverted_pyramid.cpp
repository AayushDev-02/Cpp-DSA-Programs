#include <iostream>
using namespace std;

int main(){
    int n =10;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(j == i || j == n || i==1){
                cout << j;
            }
            else{
                cout << " ";
            }
        }
        cout << endl;

    }

}