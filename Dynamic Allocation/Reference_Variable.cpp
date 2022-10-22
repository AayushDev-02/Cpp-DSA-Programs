#include <iostream>
using namespace std;

//Reference variable as a return type
int& func(int a){                       // This is a very bad practise - NEVER DO IT
    int num = a;
    int &ans = num;

    return ans;
} 


//Pointer as a return type
int* func2(int n){
    int a = n;                  
    int* ans = &a;                      // This is a very bad practise - NEVER DO IT

    return ans;
}


void update2 (int &n){
    n++;
}

void update1 (int n){
    n++;
}

int main(){

    int i =5;
    
    //creating a refernce variable
    int &j =i;

    cout <<" Value of i : " <<  i << endl;
    cout <<" Value of j : " <<  j << endl;
    cout << endl;

    //i++
    cout << "i++" << endl;
    i++;
    cout <<" Value of i : " <<  i << endl;
    cout <<" Value of j : " <<  j << endl;
    cout << endl;

    //j++
    cout << "i++" << endl;
    j++;
    cout <<" Value of i : " <<  i << endl;
    cout <<" Value of j : " <<  j << endl;
    cout << endl;
    
    //
    int n =5;
    int &m = n;

    //update 1
    cout << "Before : " << n << endl;
    update1(n);
    cout << "After : " << n << endl;
    
    // Update 2
    cout << "Before : " << n << endl;
    update2(n);
    cout << "After : " << n << endl;
    cout << endl;

    // //Reference Variable as return type :
    // int a = 10;
    // cout << func(a); //BAD PRACTISE

    return 0;
}