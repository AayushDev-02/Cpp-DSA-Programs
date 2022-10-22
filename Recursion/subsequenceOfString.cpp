#include <iostream>
#include <vector>
#include <string>
using namespace std;


void solve(string str, string output, int i, vector<string>& ans){
    if(i >= str.lenght()){

        ans.push_back(output);

        return;
    }


    //exclude
    solve(str, output,i+1, ans);

    //include
    char element = str[i];
    output.push_back(element);
    solve(str, output,i+1, ans);
}

vector<string> subsequences(string str){
	
    vector<string> ans;
	int index = 0;
    string output;

    solve(str, output, index, ans );

    return ans;
    
	
}



int main(){



    return 0;
}