#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using Graph = vector<vector<int>>;

int dig(ll N){
    int key = 0;
    while(N / 10 > 0){
        N /= 10;
        key++;
    }
    key++;
    return key;
}

int main(){
    ll N;
    cin >> N;
    int digits = dig(N); 
    ll ans = 0;
    ll key = 9;
    ll key2 = 0;
    for(int i = 1; i < digits; i++){
        ans += (key%998244353)*((key + 1)%998244353)/2;
        key2 += key;
        key *= 10;
    }
    if(digits == 1){
        ans += N * (N + 1) / 2;
        ans %= 998244353;
    }
    else{
        ll a = N - key2;
        ans += (a%998244353)*((a+1)%998244353)/2;
    }
    cout << ans%998244353 << endl;
    return 0;
}