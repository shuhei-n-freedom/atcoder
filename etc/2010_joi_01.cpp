#include<bits/stdc++.h>
using namespace std;
static const int mod = 100000;
int main(){
    int N, m;
    cin >> N >> m;
    vector<int> S(N);
    S[0] = 0;
    for(int i = 0; i < N - 1; i++){
        int tmp;
        cin >> tmp;
        S[i + 1] = S[i] + tmp;
    }
    int ans = 0;
    int key = 0;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        ans += abs(S[key + tmp] - S[key]);
        ans %= mod;
        key += tmp;
    }
    cout << ans << endl;
    return 0;
}