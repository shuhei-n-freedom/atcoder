#include<bits/stdc++.h>
using namespace std;

static const int MAX = 310;
static const int INFTY = 1e9;

int n;
int d[MAX][MAX];

void floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(d[i][k] == INFTY){
                continue;
            }
            for(int j = 0; j < n; j++){
                if(d[k][j] == INFTY){
                    continue;
                }
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = ((i == j) ? 0 : INFTY);
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        d[a][b] = t;
        d[b][a] = t;
    }
    floyd();
    int ans = INFTY;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        for(int j = 0; j < n; j++){
            tmp = max(tmp, d[i][j]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}