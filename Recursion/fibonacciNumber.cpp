#include <iostream>
using namespace std;

int fibNumber(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }

    return (fibNumber(n-1) + fibNumber(n-2));
}

int forLoop_Method(int n){

    int first =0;
    int second = 1;
    int ans = 0;

    if(n==1){
        return 1;
    }

    for(int i =0;i < n-1 ;i++){
        ans = first+ second;
        first = second;
        second = ans;
    }

    return ans;
}


int main(){

    int n;
    cout << "Enter thr number : " << endl;
    cin >> n;

    int ans = fibNumber(n);

    cout << "Nth number in fibnacci series is : " << ans << endl;

    int ans2 = forLoop_Method(n);

    cout << "Nth number in fibnacci series using for loop : " << ans2 << endl;

    return 0;
}