#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N + 1), B(N + 1);
    A[0] = 0;
    B[0] = 0;
    for(int i = 0; i < N; i++){
        int c, p;
        cin >> c >> p;
        if(c == 1){
            A[i + 1] = A[i] + p;
            B[i + 1] = B[i];
        }
        else{
            A[i + 1] = A[i];
            B[i + 1] = B[i] + p;
        }
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        int ans1 = A[r] - A[l - 1];
        int ans2 = B[r] - B[l - 1];
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}