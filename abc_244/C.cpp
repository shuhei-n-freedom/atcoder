#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector<bool> A(2*N + 2, false);
    for(int i = 1; i < 2 * N + 2; i++){
        if(A[i]){
            continue;
        }
        else{
            cout << i << endl;
            int a;
            cin >> a;
            if(a == 0){
                return 0;
            }
            else{
                A[a] = true;
            }
        }
    }
    return 0;
}