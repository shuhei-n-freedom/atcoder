#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;
int main(){
    lb T, L, X, Y;
    int Q;
    cin >> T >> L >> X >> Y;
    cin >> Q;
    vector<lb> E(Q);
    for(int i = 0; i < Q; i++){
        cin >> E[i];
    } 

    for(int i = 0; i < Q; i++){
        lb xnow, ynow, znow;
        xnow = 0;
        ynow = - L * sin(E[i] / T * 2 * 3.14159265358979) / 2;
        znow = L * (1 - cos(E[i] / T * 2 * 3.14159265358979)) / 2;
        lb r = X*X + (Y - ynow)*(Y - ynow) + znow*znow;
        r = sqrt(r);
        lb b = X*X + (Y - ynow)*(Y - ynow);
        b = sqrt(b);
        lb ans = acos(b / r);
        cout << setprecision(14) << ans * 180 / 3.14159265358979 << endl;
    }
    return 0;
}