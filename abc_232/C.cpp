#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N, vector<int>(N)), G2(N, vector<int>(N));
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    for(int i = 0; i < M; i++){
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        G2[c][d] = 1;
        G2[d][c] = 1;
    }
    /*
    for(int i = 0; i < N; i++){
        cout << G[i].size() << endl;
    }
    for(int i = 0; i < N; i++){
        cout << G2[i].size() << endl;
    }
    */
    vector<int> P(N);
    for(int i = 0; i < N; i++){
        P[i] = i;
    }
    do{
        vector<vector<int>> G3(N, vector<int>(N));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                G3[i][j] = G2[P[i]][P[j]];
            }
        }
        if(G3 == G){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(P.begin(), P.end()));
    cout << "No" << endl;
    return 0;
}