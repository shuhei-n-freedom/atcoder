#include<bits/stdc++.h>
using namespace std;

bool check(int u){
    int divcnt = 0;
    if(u % 2 == 0){
        return false;
    }
    for(int i = 1; i < u + 1; i++){
        if(u % i == 0){
            divcnt++;
        }
    }
    if(divcnt == 8){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 1; i < N + 1; i++){
        if(check(i)){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}