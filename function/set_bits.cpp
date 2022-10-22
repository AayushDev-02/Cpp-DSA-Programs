#include <iostream>
using namespace std;

int set(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            count++;
        }

        n=n>>1;
    }
    return count;
}

int setBit(int a, int b)
{
    int count = set(a) + set(b);
    return count;
}

int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    int ans = setBit(a, b);

    cout<<"Sum of set bits in a and b are: "<<ans<<endl;

    return 0;
}