/*#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//coding by priority queue

static const ll MAX = 100009;
static const ll INFTY = (1<<21);
static const ll WHITE = 0;
static const ll GRAY = 1;
static const ll BLACK = 2;
ll N;
vector<pair<ll, ll>> adj[MAX];
ll color[MAX];
ll d[MAX];

void dijkstra(ll s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;
    for(ll i = 0; i < N; i++){
        d[i] = INFTY;
        color[i] = WHITE;
    }
    d[s] = 0;
    color[s] = GRAY;
    PQ.push(make_pair(0, s));
    while(!PQ.empty()){
        pair<ll, ll> p = PQ.top();
        PQ.pop();
        ll u = p.second;
        color[u] = BLACK;
        if(d[u] < p.first){
            continue;
        }
        for(ll i = 0; i < adj[u].size(); i++){
            ll v = adj[u][i].first;
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
    for(int i = 0; i < N; i++){
        cout << d[i] << endl;
    }
}

int main(){
    ll M;
    cin >> N >> M;
    vector<ll> d1(N), d2(N);
    for(ll i = 0; i < M; i++){
        ll a, b, c;
        a--;
        b--;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    dijkstra(0);
    for(ll i = 0; i < N; i++){
        d1[i] = d[i];
    }
    dijkstra(N - 1);
    for(int i = 0; i < N; i++){
        d2[i] = d[i];
    }
    for(int i = 0; i < N; i++){
        cout << d1[i] + d2[i] << endl;
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAX = 100009;
static const ll INFTY = (1LL<<60);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

ll n;
vector<pair<ll, ll>> adj[MAX];
ll d[MAX];

void dijkstra(ll b){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;
    for(ll i = 0; i < n; i++){
        d[i] = INFTY;
    }
    d[b] = 0;
    PQ.push(make_pair(0, b));
    while(!PQ.empty()){
        pair<ll, ll> p = PQ.top();
        PQ.pop();
        ll u = p.second;
        if(d[u] < p.first){
            continue;
        }
        for(ll i = 0; i < adj[u].size(); i++){
            ll v = adj[u][i].first;
            if(d[v] > d[u] + adj[u][i].second){
                d[v] = d[u] + adj[u][i].second;
                PQ.push(make_pair(d[v], v));
            }
        }
    }
}

int main(){
    ll m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    dijkstra(0);
    vector<ll> d1(n), d2(n);
    for(ll i = 0; i < n; i++){
        d1[i] = d[i];
    }
    dijkstra(n - 1);
    for(ll i = 0; i < n; i++){
        d2[i] = d[i];
    }
    for(ll i = 0; i < n; i++){
        cout << d1[i] + d2[i] << endl;
    }
    return 0;
}
