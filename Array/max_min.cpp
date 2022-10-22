#include <iostream>
using namespace std;

int findMax(int array[], int size)
{
    int max = INT_Min;

    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }

        // PREDEFINED FUNCTION:
        // mini = min(mini,arra[i]);           inside for loop!
    }

    return max;
}

int findMin(int array[], int size)
{
    int min = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }

        // PREDEFINED FUNCTION:
        // maxi = max(maxi,arra[i]);           inside for loop!
    }

    return min;
}

int main()
{
    int size;
    cout << "Enter the size of array : " << endl;
    cin >> size;

    int array[100];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter value at index " << i << " : ";
        cin >> array[i];
        cout << endl;
    }

    int max = findMax(array, size);
    int min = findMin(array, size);

    cout << "Max element in the array is: " << max << endl;
    cout << "Min element in the array is: " << min << endl;

    return 0;
}