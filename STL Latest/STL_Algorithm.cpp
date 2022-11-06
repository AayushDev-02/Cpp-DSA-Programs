#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int main(){

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);

    cout << "Finding 7: " <<  binary_search(v.begin(), v.end(), 7) << endl;

    cout << "Lower bound-> " << lower_bound(v.begin(),v.end(), 7) - v.begin() << endl;

    return 0;
}