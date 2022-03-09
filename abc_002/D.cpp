#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    int ans = 0;
    vector<vector<bool>> rel(N, vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        rel[x][y] = true;
        rel[y][x] = true;
    }
    for(int bit = 0; bit < (1<<N); bit++){
        vector<bool> S(N);
        for(int i = 0; i < N; i++){
            if(bit & (1<<i)){
                S[i] = true;
            }
            else{
                S[i] = false;
            }
        }
        bool check = true;
        for(int i = 0; i < N; i++){
            if(S[i] == true){
                for(int j = i + 1; j < N; j++){
                    if(S[j] == true){
                        if(rel[i][j] == false){
                            check = false;
                        }
                    }
                }
            }
        }
        int tmp = 0;
        if(check){
            for(int i = 0; i < N; i++){
                if(S[i] == true){
                    tmp++;
                }
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}