#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    string S;
    cin >> S;
    vector<char> A(S.size());
    for(int i = 0; i < S.size(); i++){
        A[i] = S[i];
    }
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size(); i++){
        cout << A[i];
    }
    cout << endl;
    return 0;
}