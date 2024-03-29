#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//index here -> index of last element
int solRec(int weight[], int value[], int index, int capacity){

    //base case - only one element
    if(index==0){
        if(weight[index] <= capacity)
            return value[index];
        else
            return 0;
        
    }

    //include exclude pattern
    int include = 0;

    if(weight[index] < capacity){
        include = value[index] + solRec(weight, value, index-1, capacity - weight[index]);
    }

    int exclude = 0 + solRec(weight, value, index-1, capacity);

    int ans = max(include, exclude);

    return ans;

}


//top down
int topDown(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp){
    //base case - only one element
    if(index==0){
        if(weight[index] <= capacity)
            return value[index];
        else
            return 0;
        
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    //include exclude pattern
    int include = 0;

    if(weight[index] < capacity){
        include = value[index] + topDown(weight, value, index-1, capacity - weight[index], dp);
    }

    int exclude = 0 + topDown(weight, value, index-1, capacity, dp);

    int ans = max(include, exclude);
    dp[index][capacity] = ans;
    return ans;
}

//bottom up approach
int bottomUp(int weight[], int value[], int n, int capacity) {

    //create a dp
    vector<vector<int>> dp(n, vector<int> (capacity+1, 0));

    //base case
    for(int i=weight[0]; i<=capacity; i++){
        if(weight[0] <= capacity){

            dp[0][i] = value[0];
        }
        else{
            dp[0][i] = 0;
        }
    }

    for(int i=1; i<n; i++){
        for(int j = 0; j<=capacity; j++){
            int include = 0;

            if(weight[i] <= j){
                include = value[i] + dp[i-1][j - weight[i]];
            }

            int exclude = 0 + dp[i][j];

            int ans = max(include, exclude);
            dp[i][j] = ans;
            
        }
    }

    return dp[n-1][capacity];

}

int spaceOpt(int weight[], int value[], int n, int capacity) {
    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    for(int i=weight[0]; i<=capacity; i++){
        if(weight[0] <= capacity) {
            prev[i] = value[0];
        }
        else{
            prev[i] = 0;
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=capacity; j++){
                int include = 0;
                if(weight[i] <= j){
                    include = value[i] +  prev[j - weight[i]];
                }

                int exclude = 0 + prev[j];

                curr[j] = max(include, exclude);
            }
            //shifting - yaha galti karunga
            prev = curr;
        }

    }
    return prev[capacity];
}

int spaceOpt2(int weight[], int value[], int n, int capacity) {
    
    vector<int> curr(capacity+1, 0);

    for(int i=weight[0]; i<=capacity; i++){
        if(weight[0] <= capacity) {
            curr[i] = value[0];
        }
        else{
            curr[i] = 0;
        }

        for(int i=1; i<n; i++){
            //move from right to left
            for(int j=capacity; j>=0; j--){
                int include = 0;
                if(weight[i] <= j){
                    include = value[i] +  curr[j - weight[i]];
                }

                int exclude = 0 + curr[j];

                curr[j] = max(include, exclude);
            }
        }

    }
    return curr[capacity];
}

int main(){

    int weight[] = {4,5,1};
    int value[] = {1,2,3};

    int n = 3;
    int capacity = 4;

    // int ans = solRec(weight, value, n-1, capacity);

    // vector<vector<int> > dp(n, vector<int> (capacity+1, -1));   //2d array dp
    // int ans =  topDown(weight, value, n-1, capacity, dp);

    // int ans = bottomUp(weight, value, n, capacity);

    int ans = spaceOpt2(weight,value,n,capacity);
    cout << "Answer: " << ans << endl;



   return 0; 
}