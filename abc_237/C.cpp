#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main(){
    string S;
    cin >> S;
    int i = 0;
    while(S[i] == 'a'){
        i++;
    }
    S = S.substr(i, S.size());
    i = S.size();
    while(S[i - 1] == 'a'){
        i--;
    }
    i = S.size() - i;
    S = S.substr(0, S.size() - i);
    bool ans = true;
    for(int j = 0; j < S.size() / 2; j++){
        if(S[j] != S[S.size() - j - 1]){
            ans = false;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}