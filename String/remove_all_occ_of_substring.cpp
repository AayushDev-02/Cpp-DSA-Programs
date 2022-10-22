#include <iostream>
using namespace std;

string removeOcc(string s, string part)
{
    while ((s.length() != 0) && (s.find(part) < s.length()))
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{

    string main = "daabcbaabcbc";
    string sub = "abc";

    string ans = removeOcc(main, sub);

    cout << "String after removing substring: " << endl;
    cout << ans << endl;

    return 0;
}