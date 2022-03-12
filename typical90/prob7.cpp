#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll Q;
    cin >> Q;
    ll ans = 0;
    for(ll i = 0; i < Q; i++){
        ll b;
        cin >> b;
        auto it = lower_bound(A.begin(), A.end(), b);
        if(it - A.begin() ==  0){
            cout << abs(A[it - A.begin()] - b) << endl;
        }
        else{
            cout << min(abs(A[it - A.begin()] - b), abs(A[it - A.begin() - 1] - b)) << endl; 
        }
    }
    return 0;
}