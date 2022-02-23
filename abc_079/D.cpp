#include<bits/stdc++.h>
using namespace std;
using ll = long long;

static const int INFTY = 1e9;

int d[10][10];

void floyd(){
    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            if(d[i][k] == INFTY) continue;
            for(int j = 0; j < 10; j++){
                if(d[k][j] == INFTY) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    int H, W;
    cin >> H >> W;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> d[i][j];
        }
    }
    floyd();
    vector<int> minvec(10, INFTY);
    ll ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int a;
            cin >> a;
            if(a == -1) continue;
            ans += d[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}