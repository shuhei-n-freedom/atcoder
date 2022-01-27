#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    int L, R;
    cin >> L >> R;
    cin >> S;
    L--;
    R--;
    for(int i = 0; ;i++){
        swap(S[R], S[L]);
        L++;
        R--;
        if(R < L){
            break;
        }
    }
    cout << S << endl;
    return 0;
}