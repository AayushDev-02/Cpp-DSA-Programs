#include <iostream>
using namespace std;

//not efficient and optimised
int power1(int a,int b){
    
    if(b==0){
        return 1;
    }

    return a*power1(a,b-1);


}

//Efficient and optimised 
int power2(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }

    //recursive call or recursive relation
    int ans = power2(a,b/2);

    if(b%2==0){                     //if b is even
        return ans*ans;

    }else{                          //if b is odd
        return a*ans*ans;
    }
}

int main(){

    int a,b;
    cout <<  "Enter base : ";
    cin >> a;

    cout << "Enter power: ";
    cin >> b;

    int ans = power1(a,b);
    cout << "Answer using normal approach of recursion: " << ans << endl;

    int ans2 = power2(a,b);
    cout << "Answer using efficient approach of recursion: " << ans2 << endl;


    return 0;
}