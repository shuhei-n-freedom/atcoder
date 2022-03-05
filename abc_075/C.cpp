#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
static const int INF = (1<<21);
vector<bool> seen;

void dfs(const Graph &G, int v){
    seen[v] = true;
    for(auto next_v : G[v]){
        if(seen[next_v]){
            continue;
        }
        dfs(G, next_v);
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N);
    seen.assign(N, false);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        vector<int> tmp(G[i].size());
        for(int j = 0; j < G.size(); j++){
            tmp[j] = G[i][j];
        }
        G[i].assign(0, INF);
        int count = 0;
        seen.assign(N, false);
        seen[i] = true;
        for(int k = 0; k < N; k++){
            if(seen[k]){
                continue;
            }
            dfs(G, k);
            count++;
        }
        if(count >= 2){
            ans++;
        }
        for(int j = 0; j < tmp.size(); j++){
            G[i].push_back(tmp[j]);
        }
    }
    cout << ans << endl;
    return 0;
}