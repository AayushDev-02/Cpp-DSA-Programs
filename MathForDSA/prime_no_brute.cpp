#include <iosteam>
using namespace std;

void checkPrime(int n){
    if(n<=1){
        return false;
    }

    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }

    return true;
}


int main(){

    int n;
    cin>>n;

    checkPrime(n);


    return 0;
}