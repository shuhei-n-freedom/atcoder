#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    vector<char> S(3);
    vector<char> T(3);
    for(int i = 0; i < 3; i++){
        cin >> S[i];
    }
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        cin >> T[i];
        if(T[i] != S[i]){
            cnt++;
        }
    }
    if(cnt == 0 || cnt == 3){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}