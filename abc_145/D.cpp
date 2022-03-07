#include<bits/stdc++.h>
using namespace std;

const int MAX = 5100000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    int X, Y;
    cin >> X >> Y;
    if((X + Y) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    int n = (2 * Y - X) / 3;
    int m = (2 * X - Y) / 3;
    if(n < 0 || m < 0){
        cout << 0 << endl;
        return 0;
    }
    COMinit();
    cout << COM(n + m, n) << endl;
    return 0;
}