#include <iostream>
#include <vector>
using namespace std;


//factorial -------------------------------
int fact(int n){
    
    //base case
    if(n==0){
        return 1;
    }

    //RR
    return n * fact(n-1);

}

// int main(){
//     int n;
//     cin >> n;

//     int ans = fact(n);
//     cout << "Factorial is: " << ans;



//     return 0;
// }

//factorial -------------------------------------------------------------------------



//fibonnacci number
// -----------------------------------------------------------------------------------------------------------------------------------------

int fib(int n){

    if(n==0 ){
        return 0;
    }else if(n==1){
        return 1;
    }

    return (fib(n-1) + fib(n-2));


}



// int main(){

//     int n;
//     cin >> n;

//     int ans = fib(n);
//     cout << "The nth index fibonnaci number is : " << ans;
//     cout << endl;
//     cout << endl;
    
//     //print fib series
//     for(int i=0; i< n ;i++){
//         cout << fib(i) << " ";
//     }
//     cout << endl;
   


//     return 0;
// }
// -----------------------------------------------------------------------------------------------------------------------------------------


// Nth Stair Problem -- This method gives TLE
// -----------------------------------------------------------------------------------------------------------------------------------------

int nthStair(int n){
    if(n<0){
        return 0;
    }else if( n==0 ){
        return 1;
    }

    return nthStair(n-2) + nthStair(n-1);
}




// int main(){

//     cout << "Nth Stair Problem : " << endl;

//     int n;
//     cin >> n;
    
//     cout << "Different ways to reach nth stair : " << nthStair(n) << endl;


//     return 0;
// }

// -----------------------------------------------------------------------------------------------------------------------------------------



// Say Digits:
// -------------------------------------------------------------------------------------------------------------------------------------------------------------

void sayDigit(string arr[], int n){

    if(n==0){
        return;
    }

    int digit = n%10;
    n= n/10;

    sayDigit(arr, n);

    cout << arr[digit] << " ";


}


// int main(){

//     cout << "Say Digit Problem : " << endl;

//     int n;
//     cin >> n;
    
//     string arr[10] = {"Zero", "One" ,"Two" , "Three", "Four" , "Five" , "Six", "Seven", "Eight", "Nine"};
    
//     sayDigit(arr, n);

//     return 0;
// }
// -------------------------------------------------------------------------------------------------------------------------------------------------------------


// Check if function is sorted of not

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

bool isSorted(int arr[], int n ){

    if(n==0 || n==1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }else{
        return isSorted(arr+1, n-1);
    }

}




// int main(){

//     cout << " Check if function is sorted of not: " << endl;

//     int n;
//     cin >> n;

//     int *arr= new int[n];

//     for(int i=0 ; i < n ;i++){
//         cin >> arr[i];
//     }
//     cout << endl;

//     bool ans;
//     ans = isSorted(arr, n);

//     if(ans){
//         cout << "Array is sorted" << endl;
//     }else{
//         cout << "Array is not sorted" << endl;
//     }
//     return 0;
// }




// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Sum of array 

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

int sumArray(int arr[], int n ){

    if(n==0){
        return 0;
    }
    

    return arr[0] + sumArray(arr+1, n-1);


}


// int main(){

//     cout << " Sum of array: " << endl;

//     int n;
//     cin >> n;

//     int *arr= new int[n];

//     for(int i=0 ; i < n ;i++){
//         cin >> arr[i];
//     }
//     cout << endl;

//     int ans;
//     ans = sumArray(arr, n);

//     cout << "Sum of array is : " << ans << endl;
//     return 0;
// }


// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Linear Search

// -------------------------------------------------------------------------------------------------------------------------------------------------------------


bool linearSearch(int arr[],int size, int n){
    if(size==0 ){
        return false;
    }

    if(n==arr[0]){
        return true;
    }else{
        return linearSearch(arr+1, size-1, n);
    }
}



// int main(){

//     cout << "Check if function is sorted of not: " << endl;

//     int size, n;
//     cout << "size : ";
//     cin >> size;

//     cout << "n : ";
//     cin >> n;

//     int *arr= new int[size];

//     for(int i=0 ; i < size ;i++){
//         cin >> arr[i];
//     }
//     cout << endl;

//     bool ans;
//     ans = linearSearch(arr,size, n);

//     if(ans){
//         cout << "Element Found " << endl;
//     }else{
//         cout << "Element Not Found  " << endl;
//     }
//     return 0;
// }


// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Binary Search

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

bool binarySearch(int arr[], int n, int start, int end){

    if(start > end ){
        return false;
    }

    int mid = start + (end - start)/2;

    if(n == arr[mid]){
        return true;
    }

    if(n > arr[mid]){
        start = mid+1;
        return binarySearch(arr, n ,start, end);
    }else{
        end = mid - 1 ;
        return binarySearch(arr, n ,start, end);
    }

}


// int main(){

//     cout << "Check if function is sorted of not using binary search: " << endl;

//     int size, n;
//     cout << "size : ";
//     cin >> size;

//     cout << "n : ";
//     cin >> n;

//     int *arr= new int[size];

//     for(int i=0 ; i < size ;i++){
//         cin >> arr[i];
//     }
//     cout << endl;

//     bool ans;
//     int start = 0;
//     int end = n-1;

//     ans = binarySearch(arr, n, start,end);

//     if(ans){
//         cout << "Element Found " << endl;
//     }else{
//         cout << "Element Not Found  " << endl;
//     }
//     return 0;
// }



// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Reverse a String

// -------------------------------------------------------------------------------------------------------------------------------------------------------------


void reverse(string &s, int i, int j){

    //base case
    if(i>j){
        return ;
    }
    
    swap(s[i],s[j]);
    i++;
    j--;
    return reverse(s, i,j);

    //or
    // return reverseString(s,size, ++i, --j);


    
}



// int main(){

//     string s;
//     cout << "Enter string: ";
//     cin >> s;


//     int i,j;
//     i = 0;
//     j = s.length()-1;

//     reverse(s,i,j);
//     cout << "Reversed Stirng is :" << s << endl;




//     return 0;
// }



// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Palidrome String Check

// -------------------------------------------------------------------------------------------------------------------------------------------------------------


bool palindromeCheck(const string &s, int i, int j){

    if(i>j){
        return true;
    }

    if(s[i] != s[j]){
        return false;
    }else{
        return palindromeCheck(s, ++i, --j);
    }

}



// int main(){

//     string s;
//     cout << "Enter string: ";
//     cin >> s;


//     int i,j;
//     i = 0;
//     j = s.length()-1;

//     bool ans = palindromeCheck(s,i,j);
    
//     if(ans){
//         cout << "String is Palindrome " << endl;
//     }else{
//         cout << "String is not palindrome" << endl;
//     }


//     return 0;
// }

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Power using recursion

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

int power(int n, int p){
    if(p==0){
        return 1;
    }

    return n*power(n,p-1);
}


// int main(){

//     int n;
//     cout << "Enter number :";
//     cin >> n;

//     int p;
//     cout << "Enter power number :";
//     cin >> p;

//     int ans =power(n,p);
//     cout << "N to power p is: " << ans << endl;


//     return 0;
// }

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Power using recursion - efficient method

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

int power2(int a, int p ){

    if(p==0){
        return 1;
    }

    if(p%2==0){
        return power2(a,p/2) * power2(a,p/2);
    }else{
        return a*power2(a,p/2) * power2(a,p/2);

    }

}

// // int main(){

//     int n;
//     cout << "Enter number :";
//     cin >> n;

//     int p;
//     cout << "Enter power number :";
//     cin >> p;

//     int ans =power2(n,p);
//     cout << "N to power p is: " << ans << endl;


//     return 0;
// }



// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Power set of an array

// -------------------------------------------------------------------------------------------------------------------------------------------------------------


void solve(vector<int> &arr, vector<int> &output, int i, vector<vector<int>> &ans){
    if(i >= arr.size() ){
        ans.push_back(output);
        return;
    }

    //exclude case
    solve(arr, output, i+1, ans);


    //include case
    output.push_back(arr[i]);
    solve(arr, output, i+1, ans);
}


// int main(){
    
//     int n, a;
//     cout << "Enter size of array : ";
//     cin >> n;

//     vector<int> arr;

//     for(int i=0 ; i< n ; i++){
//         cin >> a;
//         arr.push_back(a);
//     }

//     for(int i=0 ;i<n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     vector<vector<int>> ans;
//     vector<int> output;

//     solve(arr, output, 0, ans);

//     cout << ans.size() << endl;
//     cout << endl;
    
//     for(int i=0 ;i < ans.size() ;i++){
        
//         for(int j = 0 ; j < ans[i].size() ; j++){
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }

//     cout << endl;
    
    
    
//     return 0;

// }


// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Subsequence of an array

// -------------------------------------------------------------------------------------------------------------------------------------------------------------


void subSequence(string &s, vector<char> &output, int i, vector<vector<char>> &ans){
    
    if(i >= s.length()){
        ans.push_back(output);
        return;
    }


    //exclude case
    subSequence(s, output, i+1, ans);

    //include case
    char element = s[i];
    output.push_back(element);
    subSequence(s, output, i+1, ans);
}




// int main(){
//     string s;
//     cout << "Enter the string: ";
//     cin >> s;

//     vector<vector<char>> ans;
//     vector<char> output;

//     subSequence(s, output, 0, ans);

//     cout << ans.size() << endl;
//     cout << endl;
    
//     for(int i=0 ;i < ans.size() ;i++){
        
//         for(int j = 0 ; j < ans[i].size() ; j++){
//             cout << ans[i][j] << "";
//         }
        
//         cout <<"." << endl;
//     }

    

//     cout << endl;

//     return 0;

// }


// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Phone Keypad Problem

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

void keyPad(string s, string &output, int i, vector<string> &ans , string mapping[]){
   
    if( i >= s.length()){
        ans.push_back(output);
        return;
    }

    int number = s[i] - '0';
    string value = mapping[number];

    for(int j=0; j < value.length() ; j++){

        output.push_back(value[i]);
        keyPad(s, output, i+1, ans, mapping);

        output.pop_back(); // backtracking
    }





}





// int main(){

//     string no;
//     cout << "Enter string of numbers: " ;
//     cin >> no;

//     string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

//     vector<string> ans;
//     int i = 0;
//     string output;
    

//     keyPad(no, output, i, ans, mapping);

//     cout << ans.size() << endl;
//     cout << endl;

//     for(int i=0; i< ans.size(); i++){
//         cout << ans[i] << endl;
//     }
//     cout << endl;


//     return 0;
// }


// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Permutation of a string

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

void permutation(string s,int i, vector<string> &ans ){
    if(i >= s.length()){
        ans.push_back(s);
        return;
    }

    for(int j =i; j< s.length() ; j++){
        swap(s[i], s[j]);
        permutation(s, i+1, ans);

        //backtracking
        swap(s[i], s[j]);
    }
}


// int main(){

//     string s;
//     cout << "Enter string : " ;
//     cin >> s;

//     vector<string> ans;
//     int i=0;

//     permutation(s,i, ans);

//     for(int i=0; i< ans.size() ; i++){
//         cout << ans[i] << " ";
//     }
//     cout << endl;


//     return 0;
// }


// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Permutation of a numbers

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

void permutation2(vector<int> nums,int i, vector<vector<int>> &ans ){
    if(i >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j =i; j< nums.size() ; j++){
        swap(nums[i], nums[j]);
        permutation(nums, i+1, ans);

        //backtracking
        swap(nums[i], nums[j]);
    }
}


// int main(){

//     vector<int> nums;
//     int size, n;
//     for(int i=0 ;i<size ;i++){
//         cin >> n;
//         nums.push_back(n);
//     }

//     cout << endl;

//     for(int i=0 ;i<size ;i++){
//         cout << nums[i] << endl;
//     }

//     vector<vector<int>> ans;
//     int i=0;

//     permutation2(nums,i, ans);

//     for(int i=0; i< ans.size() ; i++){
//         cout << ans[i] << " ";
//     }
//     cout << endl;


//     return 0;
// }



// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// Rat in A Maze

// -------------------------------------------------------------------------------------------------------------------------------------------------------------

// bool isSafe(int x, int y, int n, vector<vector<int> &visited, int, vector<vector<int>> &m ){

//     if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
//             return true;
//         }else{
//             return false;
//         }

// }


// void ratMaze(vector<vector<int>> &m, int n,vector<string> &ans, int x, int y, vector<vector<int>> visited, string path ){
//     if(x==n-1 && y==n-1){
//         ans.push_back(path);
//         return;
//     }

//     visited[x][y] = 1;

//     //Down
//     int newx= x+1;
//     int newy= y;

//     if(isSafe(newx,newy, n ,visited, m)){
//         path.push_back('D');
//         solve(m,n,ans,newx, newy, visited, path);
            
//         path.pop_back(); // backtracking
//     }

//     //left
//     newx = x;
//     newy = y-1;
        
//     if(isSafe(newx,newy, n ,visited, m)){
//                path.push_back('L');
//             solve(m,n,ans,newx, newy, visited, path);
            
//             path.pop_back(); // backtracking
//         }

// }



// vector<string> findPath(vector<vector<int>> &m, int n){

//     vector<string> ans;

//     if(m[0][0] == 0){
//         return ans;
//     }

//     int src_x = 0;
//     int src_y = 0;

//     vector<vector<int>> visited = m;

//     for(int i=0; i< n ;i++){
//         for(int j =0 ; j< n ;j++){
//             visited[i][j] = 0;
//         }
//     }

//     string path ="";

//     ratMaze(m,n,ans,src_x, src_y, visited, path);

//     sort(ans.begin(), ans.end());


// }



// int main(){

// }













