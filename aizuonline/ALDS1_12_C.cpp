#include<bits/stdc++.h>
using namespace std;

//coding by priority queue

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int>> adj[MAX];

void dijkstra(){
    priority_queue<pair<int, int>> PQ;
    int color[MAX];
    int d[MAX];
    for(int i = 0; i < n; i++){
        color[i] = WHITE;
        d[i] = INFTY;
    }
    d[0] = 0;
    PQ.push(make_pair(0, 0));
    color[0] = GRAY;
    while(!PQ.empty()){
        pair<int, int> p = PQ.top();
        PQ.pop();
        int u = p.second;
        color[u] = BLACK;
        if(d[u] < p.first * -1){
            continue;
        }
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].first;
            if(color[j] == BLACK){
                continue;
            }
            if(d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v] * -1, v));
                color[v] = GRAY;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main(){
    int k, u, v, c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> u >> k;
        for(int j = 0; j < k; j++){
            cin >> v >> c;
            adj[u].push_back(make_pair(v, c));
        }
    }
    dijkstra();
    return 0;
}