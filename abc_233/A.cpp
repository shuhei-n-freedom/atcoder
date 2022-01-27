#include<bits/stdc++.h>
using namespace std;
int main(){
    int X, Y;
    cin >> X >> Y;
    int N = Y - X;
    if(N <= 0){
        cout << 0 << endl;
    }
    else if(N % 10 == 0){
        cout << N / 10 << endl;
    }
    else{
        cout << N / 10 + 1 << endl;
    }
    return 0;
}