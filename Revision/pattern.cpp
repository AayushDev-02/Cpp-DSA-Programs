#include <iostream>
using namespace std;

void solidPattern(int row, int col){

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout <<  "*" << " ";
        }

        cout << endl;
    }

}
void squarePattern(int row){

    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            cout <<  "*" << " ";
        }

        cout << endl;
    }

}

void hollowRectangle(int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i == 0 || i==row-1){
                cout << "*" << " ";
            }
            else{
                if(j == 0 || j==col-1){
                    cout << "*" << " ";
                }
                else{
                    cout << " " << " ";
                }
            }
        }
        cout << endl;
    }
}

void halfPyramid(int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout << "*" <<  " ";
        }

        cout << endl;
    }

}
void invertedHalfPyramid(int n){

    for(int i=0; i<n; i++){
        for(int j=n; j>i; j--){
            cout <<  "*" <<  " ";
        }

        cout << endl;
    }

}

void numericHalfPyramid(int n){

    for(int i=0; i<n; i++){
        for(int j=1; j<i+2; j++){
            cout <<  j << " ";
        }
        cout << endl;
    }

}

void numericInvertedHalfPyramid(int n){

    for(int i=0; i<n; i++){
        for(int j=n; j>i; j-- ){
            cout << n-j+1 << " ";
        }
        cout << endl;
    }

}

void fullPyramid(int n){
    for(int i=0; i<n; i++){
        int k=0;
        for(int j=0; j<(2*n-1); j++){
            if( j < n-i-1){
                cout <<  " " <<  " ";
            }
            else if( k < 2*i + 1){
                cout << "*" << " ";
                k++;
            }
            else{
                cout << " ";
            }
        }

        cout << endl;
    }
}

void hollowInvertedHalfPyramid(int n){
    for(int i=0; i<n; i++){
        for(int j=n; j>i; j--){
            if(i == 0 || i==n-1){
                cout <<  "*" << " ";
            }
            else{
                if( j == i+1 || j==n ){
                    cout << "*" <<  " ";
                }
                else{
                    cout << " " << " ";
                }
            }
        }
        cout << endl;

    }
}

int main(){

    solidPattern(3,5);
    cout << endl;
    squarePattern(4);
    cout << endl;
    hollowRectangle(3,5);
    cout << endl;
    halfPyramid(5);
    cout << endl;
    invertedHalfPyramid(5);
    cout << endl;
    numericHalfPyramid(5);
    cout << endl;
    numericInvertedHalfPyramid(5);
    cout << endl;
    fullPyramid(6);
    cout << endl;
    hollowInvertedHalfPyramid(6);
    return 0;
}