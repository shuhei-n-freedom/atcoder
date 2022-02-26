#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A(10);
    int key;
    for(int i = 0; i < 10; i++){
        cin >> A[i];
    }
    int a = A[0];
    int b = A[a];
    int c = A[b];
    cout << c << endl;
    return 0;
}