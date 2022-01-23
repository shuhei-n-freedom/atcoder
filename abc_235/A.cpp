#include<bits/stdc++.h>
using namespace std;
int main(){
    string abc;
    cin >> abc;
    int a = (abc.at(0) - '0') * 100 + (abc.at(1) - '0') * 10 + (abc.at(2) - '0');
    int b = (abc.at(1) - '0') * 100 + (abc.at(2) - '0') * 10 + (abc.at(0) - '0');
    int c = (abc.at(2) - '0') * 100 + (abc.at(0) - '0') * 10 + (abc.at(1) - '0');
    cout << a + b + c << endl;
    return 0;
}