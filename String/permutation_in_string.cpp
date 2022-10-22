#include <iostream>
using namespace std;

bool checkEqual(int a[26], int b[26]){
    for(int i=0;i<26;i++){

        if(a[i]!=b[i]){

            return 0;

        }
    }
    return 1;
}





bool checkInclusion(string s1, string s2){

    int count[26]={0};

    for(int i=0;i<s1.length();i++){

        int index=s1[i]-'a';
        count[index]++;    

    }

    //traverse s2 string in window of size s1 length and compare

    int i=0;
    int windowSize = s1.length();
    int count2[26]={0};

    while(i < windowSize && i<s2.length()){
        int index = s2[i]-'a';
        count2[index]++;
        i++;
    }

    if(checkEqual( count1, count2)){
        return 1;
    }

    while(i<s2.length()){

        char newchar=s2[i];
        int index=newchar-'a';

        count2[index]++;

        char oldChar=s2-[windowsize];
        index=oldchar-'a';
        count2[index]--;

        i++;
    }

    if(checkEqual( count1, count2)){
        return 1;
    }

    return 0;
}


int main(){

    string s1="ab";
    string s2="eidbaooo";

    if(checkInclusion(s1,s2)){
        cout<<"s2 contains one permutation of s1"<<endl;
    }else{
        cout<<"False";
    }

    return 0;
}