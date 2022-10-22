#include <iostream>
using namespace std;
int main()
{
    int a = 2;
    while (1)
    {
        switch (a)
        {
        case 1:
            cout << "ONE" << endl;
            break;

        case 2:
            continue;
            cout << "Second" << endl;
            // break;
        
        default: cout<<"Default"<<endl;
        }
        cout << "LMAO" << endl;
        exit(0);
    }

    return 0;
}