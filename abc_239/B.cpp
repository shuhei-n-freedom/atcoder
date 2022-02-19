#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
int main(){
    string X;
    cin >> X;
    if(X.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    if(X[0] == '-' && X.size() == 2){
        cout << -1 << endl;
        return 0;
    }
    if(X[0] == '-'){
        if(X[X.size() - 1] == '0'){
            for(int i = 0; i < X.size() - 1; i++){
                cout << X[i];
            }
            cout << endl;
        }
        else{
            string A = "";
            for(int i = 1; i < X.size() - 1; i++){
                A += X[i];
            }
            ll x = stoll(A);
            x++;
            cout << '-';
            cout << x << endl;
        }
    }
    else{
        for(int i = 0; i < X.size() - 1; i++){
            cout << X[i];
        }
        cout << endl;
    }
    return 0;
}