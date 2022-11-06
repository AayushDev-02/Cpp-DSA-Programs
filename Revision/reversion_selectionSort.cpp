#include <iostream>
using namespace std;

void sort(int *arr, int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[minIndex], arr[i]);
    }
}

int main()
{

    int n = 6;
    int arr[n] = {2, 4, 0, 1, 5, 6};

    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}