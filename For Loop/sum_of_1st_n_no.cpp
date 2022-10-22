#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    int sum=0;
    for(int i=0;i<=n;i++){
        sum+=i;
    }

    cout<<"Sum of first "<<n<<" number is: "<<sum<<endl;
    return 0;
}