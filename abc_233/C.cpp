#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

ll ans = 0;
ll N, X;

void dfs(const Graph &G, ll pos, ll mult){
    if(pos == N){
        if(mult == X){
            ans++;
        }
        return;
    }
    for(ll i = 0; i < G[pos].size(); i++){
        if(mult > X / G[pos][i]){
            continue;
        }
        dfs(G, pos + 1, mult*G[pos][i]);
    }
}

int main(){
    cin >> N >> X;
    Graph G(N);
    for(ll i = 0; i < N; i++){
        ll L;
        cin >> L;
        for(ll j = 0; j < L; j++){
            ll a;
            cin >> a;
            G[i].push_back(a);
        }
    }
    dfs(G, 0, 1);
    cout << ans << endl;
    return 0;
}