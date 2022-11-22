#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerIndex(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {

        int curr = arr[i];

        while(s.top()!=-1 && arr[s.top()] >= curr){
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}


vector<int> prevtSmallerIndex(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i = 0; i<n; i++)
    {

        int curr = arr[i];

        while(s.top()!=-1 && arr[s.top()] >= curr){
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{

    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerIndex(heights, n);
    
    vector<int> prev(n);
    prev = prevSmallerIndex(heights, n);

    int area = INT_MIN;

    for(int i=0; i<n; i++){
        int len = heights[i];


        if(next[i] == -1){
            next[i] = n;
        }

        int width = next[i] - prev[i] - 1;
        
        int newArea = len*width; 
        area = max(area, newArea);
    }

    return area;
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