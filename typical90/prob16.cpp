#include<bits/stdc++.h>
using namespace std;
using ll = long long;
static const int INF = (1<<21);
int main(){
    ll N;
    cin >> N;
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = INF;
    for(ll i = 0; i <= 9999; i++){
        for(ll j = 0; j <= 9999 - i; j++){
            ll tmp = N - i * a - j * b;
            ll tmp2 = i + j + tmp / c;
            if(tmp % c != 0 || tmp < 0 || tmp2 > 9999){
                continue;
            }
            ans = min(ans, tmp2);
        }
    }
    cout << ans << endl;
    return 0;
}