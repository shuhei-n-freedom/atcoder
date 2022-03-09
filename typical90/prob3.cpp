#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int N;

vector<int> bfs(int v, const Graph &G, vector<int> d){
    for(int i = 0; i < N; i++){
        d[i] = -1;
    }
    queue<int> que;
    d[v] = 0;
    que.push(v);
    while(!que.empty()){
        int t = que.front();
        que.pop();
        for(auto nv : G[t]){
            if(d[nv] != -1){
                continue;
            }
            d[nv] = d[t] + 1;
            que.push(nv);
        }
    }
    return d;
}

int main(){
    cin >> N;
    Graph G(N);
    vector<int> d(N);
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    d = bfs(0, G, d);
    int m = -1, mid = -1;
    for(int i = 0; i < N; i++){
        if(m < d[i]){
            m = d[i];
            mid = i;
        }
    }
    d = bfs(mid, G, d);
    int ans = -1;
    for(int i = 0; i < N; i++){
        if(ans < d[i]){
            ans = d[i];
        }
    }
    cout << ans + 1 << endl;
    return 0;
}