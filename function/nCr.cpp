#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n > 1)
    {
        return (n * factorial(n - 1));
    }
    else
    {
        return 1;
    }
}

int nCr_func(int n, int r)
{
    int num = factorial(n);
    int deno = factorial(r) * factorial(n - r);

    return num / deno;
}

int main()
{
    int n, r;
    cin >> n;
    cin >> r;

    int ans = nCr_func(n, r);

    cout << "Answer is :" << ans;

    return 0;
}