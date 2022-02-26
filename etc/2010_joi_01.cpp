#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int> rank, p;
        DisjointSet(){}
        DisjointSet(int size){
            rank.resize(size, 0);
            p.resize(size, 0);
            for(int i = 0; i < size; i++) makeSet(i);
        }
        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }
        bool same(int x, int y){
            return findSet(x) == findSet(y);
        }
        void unite(int x, int y){
            link(findSet(x), findSet(y));
        }
        void link(int x, int y){
            if(rank[x] > rank[y]){
                p[y] = x;
            }
            else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y]++;
                }
            }
        }
        int findSet(int x){
            if(x != p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};

class Edge{
    public:
        int source, target, cost;
        Edge(int source = 0, int target = 0, int cost = 0):
        source(source), target(target), cost(cost){}
        bool operator < (const Edge &e) const {
            return cost < e.cost;
        }
};

int kruskal(int N, vector<Edge> edges, int K){
    int totalCost = 0;
    sort(edges.begin(), edges.end());
    DisjointSet dset = DisjointSet(N);
    for(int i = 0; i < N; i++){
        dset.makeSet(i);
    }
    int source, target;
    int size = N;
    for(int i = 0; i < edges.size(); i++){
        if(size == K) break;
        Edge e = edges[i];
        if(!dset.same(e.source, e.target)){
            totalCost += e.cost;
            dset.unite(e.source, e.target);
            size--;
        }
    }
    return totalCost;
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<Edge> edges;
    for(int i = 0; i < M; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        a--;
        b--;
        edges.push_back(Edge(a, b, cost));
    }
    cout << kruskal(N, edges, K) << endl;
    return 0;
}