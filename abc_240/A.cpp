#include<bits/stdc++.h>
using namespace std;
int main(){
    int A, B;
    cin >> A >> B;
    if(A == 1){
        if(B == 10){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(A + 1 == B){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}