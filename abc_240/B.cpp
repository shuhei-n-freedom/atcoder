#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    set<ll> S;
    for(int i = 0; i < N; i++){
        ll a;
        cin >> a;
        S.insert(a);
    }
    cout << S.size() << endl;
    return 0;
}