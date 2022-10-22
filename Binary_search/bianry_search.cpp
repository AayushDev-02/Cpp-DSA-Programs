#include <iostream>
using namespace std;

int BinarySearch(int array[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (array[mid] == key)
        {
            return mid;
        }
        if (array[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (( end - start) / 2);
    }
    return -1;
}

int main()
{

    cout << "Enter size: " << endl;
    int size;
    cin >> size;

    int arr[size];
    cout << "Enter values of the array in asc or desc order: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key: " << endl;
    cin >> key;

    int ans = BinarySearch(arr, size, key);

    if (ans == -1)
    {
        cout << "Key not found!";
    }
    else
    {
        cout << "Key found at index: " << ans << endl;
    }
    return 0;
}