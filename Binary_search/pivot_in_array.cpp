#include <iostream>
using namespace std;

int Pivot(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{

    int arr[5] = {7, 9, 1, 2, 3};
    int pivot = Pivot(arr, 5);

    cout << "The pivot element in the array is: " << pivot;

    return 0;
}