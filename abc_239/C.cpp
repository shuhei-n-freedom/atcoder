#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
int main(){
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<ll> A(8), B(8);
    A = {2, 1, -1, -2, -2, -1, 1, 2};
    B = {1, 2, 2, 1, -1, -2, -2, -1};
    set<pair<ll, ll>> S;
    for(int i = 0; i < 8; i++){
        ll newx = x1 + A[i];
        ll newy = y1 + B[i];
        pair<ll, ll> p  = make_pair(newx, newy);
        S.insert(p);
    }
    for(int i = 0; i < 8; i++){
        ll newx = x2 + A[i];
        ll newy = y2 + B[i];
        pair<ll, ll> p  = make_pair(newx, newy);
        if(S.count(p)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}