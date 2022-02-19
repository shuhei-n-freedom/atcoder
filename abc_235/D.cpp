#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int A, N;
const int M = 1000000;
const int I = 1001001001;

auto push(int v, int d, vector<int> G, queue<int> que){
    if(G[v] != I){
        return;
    }
    G[v*A] = d + 1;
    que.push(v);
}

int main(){
    cin >> A >> N;
    vector<int> G(M, I);
    queue<int> que;
    push(1, 0, G, que);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        int d = G[v];
        if(ll (v) * A < M){
            push(v * A, d + 1, G, que);
        }
        if(v >=10 && v % 10 != 0){
            string s = to_string(v);
            int len = s.size();
            rotate(s.begin(), s.end() + len - 1, s.end());
            int u = stoi(s);
            push(u, d + 1, G, que);
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