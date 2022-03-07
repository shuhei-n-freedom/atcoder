#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int d, N, M;
    cin >> d >> N >> M;
    vector<int> A(N + 1);
    for(int i = 0; i < N + 1; i++){
        if(i == 0){
            A[i] = 0;
        }
        else if(i == N){
            A[i] = d;
        }
        else{
            int d;
            cin >> d;
            A[i] = d;
        }
    }
    sort(A.begin(), A.end());
    ll ans = 0;
    for(int i = 0; i < M; i++){
        int k;
        cin >> k;
        int index = lower_bound(A.begin(), A.end(), k) - A.begin();
        ans += min(abs(A[index - 1] - k), abs(A[index] - k));
    }
    cout << ans << endl;
    return 0;
}