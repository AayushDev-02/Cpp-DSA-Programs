#include <iostream>
using namespace std;

int factorial(int n){

    // cout << n << endl;

    //Base case 
    if(n == 0){
        return 1;
    }

    // //choti problem
    int smallerProblem = factorial(n-1);

    // //Badi problem
    int biggerProblem = n * smallerProblem;

    return biggerProblem;

    //in one line
    // return n * factorial(n-1); -- important  
}


int main(){

    int n ;
    cout << "Enter number : ";
    cin >> n;

    int ans = factorial(n);

    cout << "Factorial is : " << ans;


    return 0;
}