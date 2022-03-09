#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector<string> ans;
    for(int bit = 0; bit < (1<<N); bit++){
        string S = "";
        for(int i = 0; i < N; i++){
            if(bit & (1<<i)){
                S += '(';
            }
            else{
                S += ')';
            }
        }
        int tmp = 0;
        bool check = true;
        for(int i = 0; i < N; i++){
            if(S[i] == '('){
                tmp++;
            }
            else{
                tmp--;
            }
            if(tmp < 0){
                check = false;
                break;
            }
            if(tmp != 0 && i == N - 1){
                check = false;
            }
        }
        if(check){
            ans.push_back(S);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}