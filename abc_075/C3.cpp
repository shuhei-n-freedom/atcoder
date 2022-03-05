#include<bits/stdc++.h>
using namespace std;

struct unionfind{
    vector<int> par;

    unionfind(int N) : par(N){
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
        par[rx] = ry;
    }
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    int ans = 0;
    for(int i = 0; i < M; i++){
        unionfind tree(N);
        for(int j = 0; j < M; j++){
            if(j != i){
                tree.unite(A[j], B[j]);
            }
        }
        bool tmp = true;
        for(int j = 1; j < N; j++){
            if(tree.root(j) != tree.root(j - 1)){
                tmp = false;
            }
        }
        if(!tmp){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}