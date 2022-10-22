#include <iostream>
using namespace std;

int score = 15;     // global variable

void a(int& i){

    char ch = 'a'; // local variable

    cout << i << endl;
    // b(i);

    cout << score << " in a " << endl;

    score++; // updating global variable

}

void b(int& i){

    cout << score << " in b " << endl;
}


int main(){

    int i = 5;

    {
        int i =2; //local variable - not accessible outside
        cout << i << endl;
    }

    cout << i << endl;

    cout << score << " in main " << endl;

    a(i);
    b(i);

    return 0;
}