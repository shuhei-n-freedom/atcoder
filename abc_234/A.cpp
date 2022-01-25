#include<bits/stdc++.h>
using namespace std;
int func(int t){
    return t*t + 2*t + 3;
}
int funcc(int t){
    return func(func(func(t) + t) + func(func(t)));
}
int main(){
    int t;
    cin >> t;
    cout << funcc(t) << endl;
    return 0;
}