#include<bits/stdc++.h>
using namespace std;
const int limit = 50;
int N, M;
int A[limit], B[limit];
bool G[limit][limit];
bool seen[limit];

void dfs(int v){
    seen[v] = true;
    for(int next_v = 0; next_v < N; next_v++){
        if(G[v][next_v] == false){
            continue;
        }
        if(seen[next_v]){
            continue;
        }
        dfs(next_v);
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        G[A[i]][B[i]] = true;
        G[B[i]][A[i]] = true;
    }
    int ans = 0;
    for(int i = 0; i < M; i++){
        G[A[i]][B[i]] = false;
        G[B[i]][A[i]] = false;
        for(int j = 0; j < N; j++){
            seen[j] = false;
        }
        dfs(0);
        bool tmp = false;
        for(int j = 0; j < N; j++){
            if(!seen[j]){
                tmp = true;
            }
        }
        if(tmp){
            ans++;
        }
        G[A[i]][B[i]] = true;
        G[B[i]][A[i]] = true;
    }
    cout << ans << endl;
    return 0;
}