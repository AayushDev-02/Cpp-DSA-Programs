#include <iostream>
using namespace std;

int sum(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans + arr[i];
    }

    return ans;
}

int main()
{
    int size;
    cin >> size;

    int array[100];

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    int ans = sum(array, size);

    cout << "The sum of elements of an array is: " << ans << endl;

    return 0;
}