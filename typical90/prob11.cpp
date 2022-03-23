#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll N;
    cin >> N;
    vector<ll> D(N), C(N), S(N);
    vector<vector<ll>> dp(5010, vector<ll>(5010, 0));
    for(int i = 0; i < N; i++){
        cin >> D[i] >> C[i] >> S[i];
    }
    vector<tuple<ll, ll, ll>> tup;
    for(int i = 0; i < N; i++){
        tup.push_back(make_tuple(D[i], C[i], S[i]));
    }
    sort(tup.begin(), tup.end());
    for(int i = 0; i < N; i++){
        D[i] = get<0>(tup[i]);
        C[i] = get<1>(tup[i]);
        S[i] = get<2>(tup[i]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 5000; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j + C[i] <= D[i]){
                dp[i + 1][j + C[i]] = max(dp[i + 1][j + C[i]], dp[i][j] + S[i]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 5000; i++){
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}