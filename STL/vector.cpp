#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> a;
    vector<int> b(5, 1);

    cout << "Capacity of vector: " << a.capacity() << endl;

    a.push_back(1);
    cout << "Capacity of vector: " << a.capacity() << endl;

    a.push_back(9);
    cout << "Capacity of vector: " << a.capacity() << endl;

    a.push_back(22);
    cout << "Capacity of vector: " << a.capacity() << endl;

    cout << "Size of vector: " << a.size() << endl;

    cout << "Element at 2nd index: " << a.at(2) << endl;

    cout << "Front element:  " << a.front() << endl;
    cout << "Last element:  " << a.back() << endl;

    //----------------------------------------------------------------------------------------------------------

    cout << "\n";

    cout << "Before POP: ";
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    a.pop_back();

    cout << "After POP: ";

    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    //--------------------------------------------------------------------------------------------------------------------

    cout << "\n";
    cout << "Before Clear Size: " << a.size() << endl;
    cout << "Before Clear Capacity: " << a.capacity() << endl;

    a.clear();

    cout << "After Clear Size: " << a.size() << endl;
    cout << "After Clear Capacity: " << a.capacity() << endl;

    //--------------------------------------------------------------------------------

    cout << "\n";

    cout << "Vector b: " << endl;

    for (int i : b)
    {
        cout << i << " ";
    }

    cout << endl;

    //--------------------------------------------------------------------------------

    cout << "\n";

    cout<<"Copying a vector: "<<endl;

    vector<int> copy(b);
    
    for (int i : copy)
    {
        cout << i << " ";
    }

    cout << endl;


    return 0;
}