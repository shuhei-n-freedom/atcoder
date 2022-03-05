#include<bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll mod = 998244353;
int main(){
    ll N;
    vector<ll> A(9);
    cin >> N;
    for(ll i = 1; i <= N; i++){
        if(i == 1){
            for(ll j = 0; j < 9; j++){
                A[j] = 1;
            }
        }
        else{
            vector<ll> tmp(9);
            for(int j = 0; j < 9; j++){
                tmp[j] = A[j];
            }
            for(int j = 0; j < 9; j++){
                if(j == 0){
                    A[j] = (tmp[j] % mod) + (tmp[j + 1] % mod);
                }
                else if(j == 8){
                    A[j] = (tmp[j] % mod) + (tmp[j - 1] % mod);
                }
                else{
                    A[j] = (tmp[j - 1] % mod) + (tmp[j] % mod) + (tmp[j + 1] % mod);
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < 9; i++){
        ans += (A[i] % mod);
    }
    cout << ans % mod << endl;
    return 0;
}