#include<bits/stdc++.h>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int>> adj[MAX];

void dijkstra(int r){
    priority_queue<pair<int, int>> PQ;
    int color[MAX];
    int d[MAX];
    for(int i = 0; i < n; i++){
        d[i] = INFTY;
        color[i] = WHITE;
    }
    d[r] = 0;
    PQ.push(make_pair(0, r));
    color[r] = GRAY;
    while(!PQ.empty()){
        pair<int, int> p = PQ.top();
        PQ.pop();
        int u = p.second;
        color[u] = BLACK;
        if(d[u] < p.first * (-1)){
            continue;
        }
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].first;
            if(color[v] == BLACK){
                continue;
            }
            if(d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v] * (-1), v));
                color[v] = GRAY;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl; 
    }
}

int main(){
    int e, r;
    cin >> n >> e >> r;
    for(int i = 0; i < e; i++){
        int s, t, d;
        cin >> s >> t >> d;
        adj[s].push_back(make_pair(t, d));
    }
    dijkstra(r);
    return 0;
}

