#include <iostream>
using namespace std;

void Bubble(int arr[], int size)
{
    bool swapped=false;
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(arr[j], arr[j-1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
    }
}

int main()
{

    int arr[5] = {2, 5, 3, 77, 33};
    Bubble(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}