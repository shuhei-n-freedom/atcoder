#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> A;
bool check(ll mid, ll K, ll N, ll L){
    ll cnt = 0, pre = 0;
    for(int i = 0; i < N; i++){
        if(A[i] - pre >= mid && L - A[i] >= mid){
            cnt++;
            pre = A[i];
        }
    }
    if(cnt >= K){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ll N, L, K;
    cin >> N >> L >> K;
    A.assign(N, -1);
    for(ll i = 0; i < N; i++){
        int a;
        cin >> a;
        A[i] = a;
    }
    ll left = -1;
    ll right = L + 1;
    while(right - left > 1){
        ll mid = (right + left) / 2;
        if(check(mid, K, N, L)){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    cout << left << endl;
    return 0;
}