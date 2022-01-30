#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    char a = s[0];
    s[0] = s[s.size() - 1];
    s[s.size() - 1] = a;
    cout << s << endl;
    return 0;
}