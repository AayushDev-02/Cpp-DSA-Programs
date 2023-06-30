#include <iostream>
#include <vector>
using namespace std;

//index here  = index of last element
int solveRec(int weight[], int value[], int index, int capacity){

    //base case -> only one element
    if(index == 0){
        //single item
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    //include and exclude
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solveRec(weight, value, index-1, capacity - weight[index]);
    }

    int exclude = solveRec(weight, value, index-1, capacity );

    int ans = max(include, exclude);

    return ans;

}


//since we are changing 2 states thus we need a 2d DP

//TOP DOWN APPROACH
int solveMemoization (int weight[], int value[], int index, int capacity, vector<vector<int>> &dp){

    //base case -> only one element
    if(index == 0){
        //single item
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    if(dp[index][capacity] != -1) return dp[index][capacity];

    //include and exclude
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solveMemoization(weight, value, index-1, capacity - weight[index], dp);
    }

    int exclude = solveMemoization(weight, value, index-1, capacity , dp);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];

}

// TABULATION METHOD
int solveTabulation(int weight[], int value[], int n, int capacity){

    vector<vector<int>> dp(index+1, vector<int>(capacity+1, 0));

    for(int w=0; w<=capacity; w++){
        if(weight[0] <= capacity){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    for(int index = 0; index< n; index++){
        for(int wt=0; wt <= capacity; wt++){

            //include and exclude
            int include = 0;
            if(weight[index] <= capacity){
                include = value[index] + dp[index-1][wt - weight[index]];
            }

            int exclude = dp[index-1][wt];
 
            dp[index][capacity] = max(include, exclude);


        }
    }
    
    return dp[index][capacity];

}


int main(){

    int weight[] = {4,5,1};
    int value[] = {1,2,3};
    int n = 3;
    int capacity = 4;

    // int ans = solveRec(weight, value, n-1, capacity);

    vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));
    int ans = solveMemoization(weight, value, n-1, capacity, dp);
    


    cout << "Answer: " << ans;

    return 0;
}