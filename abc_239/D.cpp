#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

bool isPrime(int a){
    for(int i = 2; i < a; i++){
        if((a % i) == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int A, B, C, D;
    vector<bool> ans(100, true);
    cin >> A >> B >> C >> D;
    for(int i = A; i <= B; i++){
        for(int j = C; j <=D; j++){
            if(isPrime(i + j)){
                ans[i] = false;
                break;
            }
        }
    }
    for(int i = A; i <= B; i++){
        if(ans[i]){
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
    return 0;
}