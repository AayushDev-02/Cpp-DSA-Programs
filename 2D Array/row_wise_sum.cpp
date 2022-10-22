#include <iostream>
using namespace std;

void largestRow(int ans[], int row)
{
    int max = INT_MIN;
    int index = -1;
    for (int i = 0; i < row; i++)
    {
        if (max < ans[i])
        {
            max = ans[i];
            index = i;
        }
    }
    cout << endl;
    cout << " Maximum row is: " << index << " with value : " << max << endl;
}

void printSum(int arr[][4], int row, int col)
{

    int ans[row];

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        ans[i] = sum;
    }

    cout << endl;

    for (int i = 0; i < 3; i++)
    {

        cout << ans[i] << " ";
    }
    cout << endl;

    largestRow(ans, row);
}

int main()
{

    int arr[3][4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "The sum of rows are: " << endl;
    printSum(arr, 3, 4);

    return 0;
}