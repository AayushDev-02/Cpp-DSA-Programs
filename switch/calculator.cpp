#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter value of a and b" << endl;
    cin >> a;
    cin >> b;

    char operation;
    cout << "Enter operation"<<endl;
    cin >> operation;

    switch (operation)
    {
    case '+':
        cout << "Sum :" << (a + b);
        break;
    case '-':
        cout << "Sub :" << (a - b);
        break;
    case '*':
        cout << "Mul :" << (a * b);
        break;
    case '/':
        cout << "Div :" << (a / b);
        break;
    default:
        cout<<"Enter valid operation"<<endl;
    }

    return 0;
}