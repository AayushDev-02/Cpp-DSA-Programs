#include <iostream>
using namespace std;

void update (int **p2){
    // p2 = p2+1 ;
     // kuch change hoga? - NO CHANGE

    // *p2 = *p2+1;
     // kuch change hoga? - YES P CHANGES

    **p2 = **p2+1;
     // kuch change hoga? - YES P2 CHANGES
}



int main(){

    int i =5;
    int *p = &i;

    int **p2 = &p;

    cout << "Sab sahi chal raha h" << endl;

    cout <<"Printing i "<< i << endl;
    cout <<"Printing i address "<< &i << endl;
    cout <<"Printing P "<< p << endl;
    cout <<"Printing P address "<< &p << endl;
    cout <<"Printing P2 "<< p2 << endl;
    cout <<"Printing P2 address "<< &p2 << endl;
    cout << endl;

    cout << "value at p : " << *p << endl;
    cout << "value at p2 : " << *p2 << endl;

    cout << endl;

    //Different ways to print value at i
    cout << "Different ways to print value at i" << endl;

    cout << "Method 1: " << i << endl;
    cout << "Method 2: " << *p << endl;
    cout << "Method 3: " << **p2 << endl;
    cout << endl;

    //Different ways to print value at p
    cout << "Different ways to print value at p" << endl;

    cout << "Method 1: " << p << endl;
    cout << "Method 2: " << *p2 << endl;
    cout << "Method 3: " << &i << endl;
    cout << endl;
    
    //Different ways to print value at p2
    cout << "Different ways to print value at p2" << endl;

    cout << "Method 1: " << p2 << endl;
    cout << "Method 2: " << &p << endl;
    cout << endl;
    
    //Double pointer in  function
    cout << "Double pointer in  function" << endl;

    cout << "Before i : " << i << endl;
    cout << "Before p : " << p << endl;
    cout << "Before p2 : " << p2 << endl;
    update(p2);
    cout << "After i : " << i << endl;
    cout << "After p : " << p << endl;
    cout << "After p2 : " << p2 << endl;
    cout << endl;





    return 0;
}