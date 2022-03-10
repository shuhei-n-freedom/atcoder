#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int cnt = 0;
    int id = -1;
    while(cnt < K){
        char key = '}';
        for(int i = id + 1; i < N - (K - cnt) + 1; i++){
            if(key > S[i]){
                key = S[i];
                id = i;
            }
        }
        cout << key;
        cnt++;
    }
    cout << endl;
    return 0;
}