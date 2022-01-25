#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    set<string> A;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }
    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        A.insert(s);
    }
    for(int i = 0; i < N; i++){
        if(A.count(S[i])){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}