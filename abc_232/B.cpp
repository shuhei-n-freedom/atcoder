#include<bits/stdc++.h>
using namespace std;
int main(){
    string S, T;
    cin >> S >> T;
    int key = (26 + T[0] - S[0]) % 26;
    string R = S;
    for(int i = 0; i < (int)S.size(); i++){
        R[i] = ((S[i] - 'a') + key) % 26 + 'a';
    }
    if(T == R){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}