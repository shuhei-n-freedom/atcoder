#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector<ll> A(N + 1);
    A[0] = 0;
    for(int i = 0; i < N; i++){
        ll a;
        cin >> a;
        A[i + 1] = A[i] + a;
    }
    for(int i = 1; i <= N; i++){
        ll ans = 0;
        for(int j = i; j < N + 1; j++){
            ll tmp = A[j] - A[j - i];
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}