#include <iostream>
#include <vector>
using namespace std;


vector<int> arr1;
vector<int> arr2 (5, 10);
vector<int> arr3 = {1,2,3,4,5};
vector<int> arr4 {1,2,3,4,5};

//accessing the elements:

arr2[3] = 10;           // will give garbage value;
arr2.at(3) = 10;     // will give out of bound excecption when accessing a unknown index    // exception safe
