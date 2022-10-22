#include <iostream>
using namespace std;


int countDistinctWays(int n) {
    //  Write your code here.
    if(n<0){
        return 0;
    }
    if(n == 0 || n==1 ){
        return 1;
    }
    
    return countDistinctWays(n-1) + countDistinctWays(n-2);

}

int main(){

    return 0;
}
