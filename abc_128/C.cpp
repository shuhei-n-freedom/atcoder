#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// まとめて入力するべき
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> S(M);
    for(int i = 0; i < M; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int tmp;
            cin >> tmp;
            tmp--;
            S[i].push_back(tmp);
        }
    }
    vector<int> P(M);
    for(int i = 0; i < M; i++){
        cin >> P[i];
    }
    ll num = 0;
    vector<bool> sw(N);
    for(int bit = 0; bit < (1<<N); bit++){
        vector<int> T;
        for(int i = 0; i < N; i++){
            if(bit & (1<<i)){
                sw[i] = true;
            }
            else{
                sw[i] = false;
            }
        }
        bool ans = true;
        for(int i = 0; i < M; i++){
            int tmp = 0;
            for(int j = 0; j < S[i].size(); j++){
                if(sw[S[i][j]]){
                    tmp++;
                }
            }
            if(tmp % 2 != P[i]){
                ans = false;
                break;
            }
        }
        if(ans){
            num++;
        }
    }
    cout << num << endl;
    return 0;
}