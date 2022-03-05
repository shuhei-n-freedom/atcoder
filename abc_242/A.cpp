#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    double A, B, C, X;
    cin >> A >> B >> C >> X;
    if(X <= A){
        cout << 1 << endl;
    }
    else if(X <= B){
        cout << setprecision(8) << C / (B - A) << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}