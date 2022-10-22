//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int first(vector<vector<int>> arr, int start, int end, int index)
    {

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            
            
            if (arr[index][mid] == 1 && (arr[index][mid - 1] == 0 || mid==0))
            {
                return mid;
            }
            else if (arr[index][mid] == 0)
            {
                end = first(arr, mid+1, end,index);
            }
            else
            {
                end = first(arr, start, (mid - 1), index);
            }
        }

        return -1;
    }

    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {

        int ans = -1;
        int max = -1;
        for (int i = 0; i < n; i++)
        {

            int index = first(arr, 0, m - 1, i);

            if (index != -1 && m - index > max)
            {
                max = m - index;
                ans = i;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends