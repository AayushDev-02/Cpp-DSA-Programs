#include <iostream>
using namespace std;
int main()
{

    // int a[10];

    // // creating an 2d array
    // int arr[3][3];

    // input in 2d array - row wise

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    // // output 2dd array

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }



    int arr2[3][4]={1,2,3,4,5,6,7,8,9,11,22,33};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    cout<<endl;
    int arr3[3][4]={{1,11,111,111},{2,22,222,2222},{3,33,333,3333}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}