#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int A, N;
    cin >> A >> N;
    const int M = 1000000;
    const int I = 1001001001;
    vector<int> G(M, I);
    queue<int> que;
    que.push(1);
    G[1] = 0;
    while(!que.empty()){
        int v = que.front();
        que.pop();
        int d = G[v];
        if(ll (v) * A < M){
            if(G[v * A] != I){
                continue;
            }
            G[v * A] = d + 1;
            que.push(v * A);
        }
        if(v >=10 && v % 10 != 0){
            string s = to_string(v);
            char ini = s[0];
            s[0] = s[s.size() - 1];
            s[s.size() - 1] = ini;
            int u = stoi(s);
            if(G[u] != I){
                continue;
            }
            G[u] = d + 1;
            que.push(u);
        }
    }
    if(G[N] == I){
        cout << -1 << endl;
    }
    else{
        cout << G[N] << endl;
    }
    return 0;
}