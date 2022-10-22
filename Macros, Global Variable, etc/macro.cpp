#include <iostream>
using namespace std;

#define PI 3.14

int main(){


    int r = 5;
    //method 1
    int area1 = 3.14 * r * r;
    cout << "Area is " << area1 << endl;

    //method 2
    double pi = 3.14;
    int area2 = pi * r * r;
    cout << "Area is " << area2 << endl;

    // method 3
    int area3 = PI * r * r;
    cout << "Area is " << area3 << endl;

    return 0; 
}