#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int n, s;
    int free;
    
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
//         top initialise
        for(int i=0; i<n; i++){
            top[i] = -1;
        }
        
//         memset(top, -1, n);
        
//         next initialise
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        
//      update last index to -1
        next[s-1] = -1;
        
        //initialise free variable
        free = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        if(free == -1){
            return false; 
        }
        
        //step 1: find index
        int index = free;
        
        //step 2: update free
        free = next[index];
        
        //step 3: insert element in arr
        arr[index] = x;
        
        //step 4: update next
        next[index] = top[m-1];
        
        //step 5: update top
        top[m-1] = index;
        
        return true;
        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //reverse of push operation
        
        //check underflow condition
        if(top[m-1] == -1){
            return -1;
        }
        
        int index = top[m-1];
         
        top[m-1] = next[index];
        
        next[index] = free;
        
        free = index;
        
        return arr[index];
    }
};