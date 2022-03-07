#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> A(5);
    for(int i = 0; i < 5; i++){
        A[i] = 2* i;
    }
    int index = lower_bound(A.begin(), A.end(), 5) - A.begin();
    cout << index << endl;
    return 0;
}