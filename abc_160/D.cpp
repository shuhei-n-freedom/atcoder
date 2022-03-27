#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<ll> A(N, 0);
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            int p;
            p = min(abs(i - j), abs(X - i) + 1 + abs(j - Y));
            p = min(p, abs(Y - i) + 1 + abs(j - X));
            A[p]++;
        }
    }
    for(int i = 1; i < N; i++){
        cout << A[i] << endl;
    }
    return 0;
}