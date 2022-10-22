#include <iostream>
using namespace std;

//method 1
int reverse(int n){
    int ans= 0;
    while(n>0){
        int digit = n%10;
        ans= ans*10+digit;
        n = n/10;
    }

    return ans;
}


void sayDigit_usingLoops(string arr[], int n){
    
    while(n>0){
        int digit = n%10;
        cout << arr[digit]<< " ";
        n = n/10;
    }

    cout << endl;
}


//Method 2
void sayDigit_usingRecursion(string arr[], int n){
    if(n==0){
        return;
    }

    int digit = n%10;
    n = n/10;

    sayDigit_usingRecursion(arr,n);

    cout << arr[digit] << " ";
}

int main(){
    
    int n;
    cin >> n;

    string arr[10] = {"Zero" , "One" , "Two","Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine" };
    
    //using reverse
    int rev = reverse(n);
    cout << "Using Loop and reverse : ";
    sayDigit_usingLoops(arr , rev);

    //using recursion

    cout << "Using recursion : ";
    sayDigit_usingRecursion(arr, n);

    cout << endl;



}