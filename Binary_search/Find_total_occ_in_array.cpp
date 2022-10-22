#include <iostream>
using namespace std;

int firstOcc(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int ans=-1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid = 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int ans=-1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid = 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    // sorted array
    int array[7] = {1, 2, 3, 3, 3, 3, 5};
    int key = 3;

    int size = 7;

    int first = firstOcc(array, size, key);
    int last = lastOcc(array, size, key);

    int total=(last-first)+1;
    cout << "Total no. occurance of " << key << " in array is: " << total << endl;

    return 0;
}