#include <iostream>
using namespace std;

int main()
{

    // creation
    int arr1[3][4];

    int arr2[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};

    int arr3[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};

    // // input - row wise
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> arr1[i][j];
    //     }
    // }


    // input - column wise
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> arr1[j][i];
    //     }
    // }

    // cout<<endl;

    // print arr1
    // cout<<"Arr1: "<<endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arr1[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // print arr2
    cout<<"Arr2: "<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }


    // print arr1
    cout<<"Arr3: "<<endl;
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