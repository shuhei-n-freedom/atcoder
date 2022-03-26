#include<bits/stdc++.h>
using namespace std;
static const int mod = 998244353;
int dp[1001001][10] = {0};
int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= 9; j++){
            for(int k = max(1, i - 1); k <= min(9, i + 1); j++){
                dp[i][k] += dp[i - 1][j];
                dp[i][k] %= mod;
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= 9; i++){
        res += dp[N][i];
        res %= mod;
    }
    cout << res << endl;
    return 0;
}