#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int si, sj, ti, tj, p;
    cin >> si >> sj >> ti >> tj >> p;
    vector<vector<bool>> h(20, vector<bool>(19));
    vector<vector<bool>> v(19, vector<bool>(20));
    for(int i = 0; i < 20; i++){
        string S;
        cin >> S;
        for(int j = 0; j < S.size(); i++){
            if(S[j] == '0'){
                h[i][j] = false;
            }
            else{
                h[i][j] = true;
            }
        }
    }
    for(int i = 0; i < 19; i++){
        string S;
        cin >> S;
        for(int j = 0; j < S.size(); j++){
            if(S[j] == '0'){
                v[i][j] = false;
            }
            else{
                v[i][j] = true;
            }
        }
    }
    int i = 0;
    string ans = "";
    while(i < 200){
        if(h[si][sj] && v[si][sj]){

        }
    }
}
