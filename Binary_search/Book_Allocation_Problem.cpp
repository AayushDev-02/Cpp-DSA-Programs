
bool isPossible(vector<int> arr, int n, int m, int mid)
{

    int student = 1;
    int pageCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageCount + arr[i] <= mid)
        {
            pageCount += arr[i];
        }
        else
        {
            student++;
            if (student > m || arr[i] > mid)
            {
                return false;
            }
            pageCount = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    int s = 0;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;

    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main(){
    return 0;
}