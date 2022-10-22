#include <iostream>
using namespace std;

int CP(int n)
{
    return (3 * n + 7);
}

int main()
{
    int n;
    cin >> n;

    int ans = CP(n);

    cout << "The nth term of the CP is: " << ans << endl;

    return 0;
}