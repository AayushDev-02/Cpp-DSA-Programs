#include <iostream>
using namespace std;

void reachHome(int src , int destination){

    cout << "Source : " << src << " Destination : "<< destination << endl;

    //Base Condition
    if(src == destination){
        cout << "PAHUNCH GAYE ! " << endl;
        return;
    }

    //Recursive relation
    reachHome( ++src , destination);

}



int main(){

    int destination = 10;
    int src = 1;

    reachHome(src,destination);


    return 0;
}