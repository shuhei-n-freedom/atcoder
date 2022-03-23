#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<int> k(4, 0);
    int key = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'S'){
            k[key]++;
        }
        else{
            key += 1;
            key %= 4;
        }
    }
    cout << k[0] - k[2] << " " << k[3] - k[1] << endl;
    return 0;
}