#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{

    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {

        int curr = arr[i];

        while(s.top() >= curr){
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    vector<int> ans = nextSmallerElement(arr,n);

    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}