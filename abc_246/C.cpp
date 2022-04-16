#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>; 

int main(){
    ll N, K, X;
    cin >> N >> K >> X;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll a;
        cin >> a;
        if(K - a / X > 0){
            K -= a / X;
            pq.push(a % X);
        }
        else{
            pq.push(a - K * X);
            K = 0;
        }
    }
    for(ll i = 0; i < N - K; i++){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
    return 0;
}