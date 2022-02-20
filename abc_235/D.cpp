#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int A, N;
    cin >> A >> N;
    const int MX = 1000000;
    const int INF = 1001001001;
    vector<int> dist(MX, INF);
    queue<int> que;
    auto push = [&](int v, int d){
        if(dist[v] != INF){
            return;
        }
        dist[v] = d;
        que.push(v);
    };
    push(1, 0);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        int d = dist[v];
        if(ll (v) * A < MX){
            push(v * A, d + 1);
        }
        if(v >=10 && v % 10 != 0){
            string s = to_string(v);
            int len = s.size();
            rotate(s.begin(), s.begin() + len - 1, s.end());
            int u = stoi(s);
            push(u, d + 1);
        }
    }
    if(dist[N] == INF){
        cout << -1 << endl;
    }
    else{
        cout << dist[N] << endl;
    }
    return 0;
}