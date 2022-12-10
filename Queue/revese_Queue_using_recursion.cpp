

//function Template for C++

//Function to reverse the queue.
void solve(queue<int> &q, queue<int> &ans){
    if(q.empty()){
        return;
    }
    
    int x = q.front();
    q.pop();
    solve(q,ans);
    
    ans.push(x);
    
}


queue<int> rev(queue<int> q)
{
    queue<int> ans;
    solve(q, ans);
    
    return ans;
    
}