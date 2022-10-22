#include <iostream>
using namespace std;

int main()
{

    // int n;
    // cout << "Enter size of 2d array : ";
    // cin >> n;

    // //  creating an 2d array
    // int **arr = new int *[n];

    // // assigning an array in heap to each pinter in the 2d array

    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = new int[n];
    // }

    // // taking input

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    // // printing output

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

// ---------------------------------------------------------------------------------------------------------------------------

//2d array with different rows and col
    int row;
    cout << "Enter row size : ";
    cin >> row;

    int col;
    cout << "Enter col size : ";
    cin >> col;

//creating 2d array
    int** arr2 = new int* [row];
    

// assigning an array in heap to each pinter in the 2d array
    for(int i=0 ; i < row ; i++){
        arr2[i] = new  int[col];
    }


// taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr2[i][j];
        }
    }
    cout << endl;

    // printing output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }


//releasing memory
    
    //firstly the assigned pointer arrays needs to be free

    for(int i=0 ; i<row ; i++){
        delete [] arr2[i];
    }

    //secondly release the array containing pointers

    delete []arr2;



    return 0;
}