#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll sum = 0;
    for(int i = 0; i < N; i++){
        sum += abs(A[i] - B[i]);
    }
    cout << sum << endl;
    return 0;
}