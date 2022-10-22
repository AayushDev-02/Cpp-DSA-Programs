#include <isotream>
using namespace std;

void insertionSort(int *arr,int size){
    
}


int main(){

    int n;
    cout << "Enter size :";
    cin >> n;

    int *arr = new int[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Sorted Array : ";

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    
    return 0;


}