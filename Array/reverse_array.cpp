#include <iostream>
using namespace std;



void reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};

    reverse(array, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}