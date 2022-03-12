#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    int ans1 = 0;
    for(int i = 0; i < N; i++){
        if(A[i] == B[i]){
            ans1++;
        }
    }
    int ans2 = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i] == B[j]){
                ans2++;
            }
        }
    }
    cout << ans1 << endl;
    cout << ans2 - ans1 << endl;
    return 0; 
}