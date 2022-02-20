#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<ll> S(N + 1);
    for(ll i = 0; i < N; i++){
        S[i + 1] = S[i] + A[i];
    }
    map<ll, ll> mp;
    ll ans = 0;
    for(ll r = 1; r < N + 1; r++){
        mp[S[r - 1]]++;
        ans += mp[S[r] - K];
    }
    cout << ans << endl;
    return 0;
}