#include <iostream>
using namespace std;

void update(int array[], int size)
{
    cout << "Inside the function" << endl;

    cout << "Update value at zero index: ";
    cin >> array[0];

    for (int i = 0; i < 3; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Going back to main" << endl;
}

int main()
{
    int arr[3] = {1, 2, 3};

    update(arr, 3);

    cout << "Printing in main function " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}