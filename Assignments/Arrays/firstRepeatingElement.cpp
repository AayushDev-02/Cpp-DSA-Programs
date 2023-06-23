#include <iostream>
using namespace std;

int firstRepeated(int arr[], int n) {
        
        int ans = -1;
        
        for(int i=0; i<n-1; i++){
            int x = arr[i];
            for(int j=i+1; j<n; j++){
                cout << x << " -> " << arr[j] << endl;
                if(arr[j] == x){
                    // cout << ans << endl;
                    ans = i+1;
                    break;
                }
            }
            if(ans!= -1) break;
        }
        
        return ans;
        
    }

int main(){

    int arr[7] = {1,5,3,4,3,5,6};
    int ans = firstRepeated(arr, 7);

    cout << "Final : " <<  ans << endl;


    return 0;
}