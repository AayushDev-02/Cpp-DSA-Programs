#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int binary = 101;
    int i = 0;
    int ans = 0;
    while (binary != 0)
    {
        int bit = binary % 10;
        if (bit==1)
        {
            ans = ans + pow(2, i);
        }

        binary = binary / 10;
        i++;
    }

    cout << "decimal: " << ans;

    return 0;
}