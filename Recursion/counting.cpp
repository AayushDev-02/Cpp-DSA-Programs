#include <iostream>
using namespace std;

void tailRecursion_print(int n){

    //base condition 
    if(n==0){
        return;
    }

    //processing
    cout << n << " ";

    //recursive relation
    tailRecursion_print(n-1);

}

void headRecursion_print(int n){

    //base condition 
    if(n==0){
        return;
    }

    //recursive relation
    headRecursion_print(n-1);

    //processing
    cout << n << " ";

}

int main(){

    int n;
    cin >> n;

    cout << "Tail Recursion" << endl;
    tailRecursion_print(n);
    cout << endl;

    cout << "Head Recursion" << endl;
    headRecursion_print(n);
    cout << endl;


    return 0;
}