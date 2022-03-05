#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct unionfind{
    vector<int> par, siz;

    unionfind(int N) : par(N), siz(N, 1){
        for(int i = 0; i < N; i++){
            par[i] = i;
        }
    }
    int root(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = root(par[x]);
    }
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return;
        }
        if(siz[rx] < siz[ry]){
            swap(x, y);
        }
        par[ry] = rx;
        siz[rx] += siz[ry];
    }
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x){
        return siz[root(x)];
    }
};

int main(){
    ll N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    unionfind tree(N);
    ll ans = N * (N - 1) / 2;
    vector<ll> Ans(M + 1);
    Ans[M - 1] = ans;
    for(ll i = M - 1; i > 0; i--){
        if(!tree.same(A[i], B[i])){
            ll tmp = tree.size(A[i]) * tree.size(B[i]);
            ans -= tmp;
        }
        Ans[i - 1] = ans;
        tree.unite(A[i], B[i]);
    }
    for(int i = 0; i < M; i++){
        cout << Ans[i] << endl;
    }
    return 0;
}