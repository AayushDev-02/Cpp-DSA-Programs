#include <iostream>
#include <stack>
using namespace std;

int minCostValid(string str){

    //step 1 - odd condition
    if(str.length() % 2 == 1){
        return -1;
    }

    //step 2 - Remove valid part
    stack<char> s;
    for(int i=0; i<str.length(); i++){

        char ch = str[i];

        if(ch == '{'){
            s.push(ch);
        }
        else{
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }else{
                s.push(ch);
            }
        }

    }

    //stack contains invalid expression now

    //step 3 - using patterns find sum (using a and b)
    int a = 0;  //count i=if close brace
    int b = 0;  // count of open brace

    while(!s.empty()){
        if(s.top() == '{'){
            b++;
        }else{
            a++;
        }

        s.pop();
    }

    int ans = ((a+1)/2 + (b+1)/2);
    return ans;

}



int main()
{

    string str;
    cin >> str;

    int cost = minCostValid(str);

    cout << "Min cost to make expression valid: " << cost << endl;
    
    return 0;
}