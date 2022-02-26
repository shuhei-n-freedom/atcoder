#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        long long b;
        cin >> b;
        bool tmp = false;
        for(int j = 0; j < N; j++){
            if(A[j] == b){
                A.erase(A.begin() + j);
                tmp = true;
            }
        }
        if(!tmp){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}