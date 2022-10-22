#include <iostream>
using namespace std;

int main()
{
    int num = 3;
    char ch = 'a';
    switch (num)
    {
    case 1:
        cout << "First" << endl;
        break;
    case 2:
        cout << "Second" << endl;
        break;
    case 3:
        switch (ch)
        {
        case 'a':
            cout << "Aayush Yadav";
            break;

        default:
            cout << "Anju Yadav";
            break;
        }
        // cout << "Second" << endl;
        break;
    default:
        cout << "Default case" << endl;
    }

    return 0;
}