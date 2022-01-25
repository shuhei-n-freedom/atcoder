#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> cnt(N + 1);
    for(int i = 0; i < 4 * N - 1; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for(int i = 1; i <= N; i++){
        if(cnt[i] == 3){
            cout << i << endl;
        }
    }
    return 0;
}