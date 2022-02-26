#include<bits/stdc++.h>
using namespace std;

static const int MAX = 150;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int>> adj[MAX];

void dijkstra(int b, int c){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    int color[MAX];
    int d[MAX];
    for(int i = 0; i < n; i++){
        d[i] = INFTY;
        color[i] = WHITE;
    }
    d[b] = 0;
    color[b] = GRAY;
    PQ.push(make_pair(0, b));
    while(!PQ.empty()){
        pair<int, int> p = PQ.top();
        PQ.pop();
        int u = p.second;
        color[u] = BLACK;
        if(d[u] < p.first){
            continue;
        }
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            if(color[v] == BLACK){
                continue;
            }
            if(d[v] > d[u] + adj[u][i].second){
                d[v] = d[u] + adj[u][i].second;
                PQ.push(make_pair(d[v], v));
                color[v] = GRAY;
            }
        }
    }
    if(d[c] == INFTY){
        cout << -1 << endl;
    }
    else{
        cout << d[c] << endl;
    }
}

int main(){
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a;
        if(a){
            cin >> b >> c >> d;
            b--;
            c--;
            adj[b].push_back(make_pair(c, d));
            adj[c].push_back(make_pair(b, d));
        }
        else{
            cin >> b >> c;
            b--;
            c--;
            dijkstra(b, c);
        }
    }
    return 0;
}