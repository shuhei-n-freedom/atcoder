#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> A(2, vector<int>(5));
    A = {
        {1,2,3,4,5},
        {6,7,8,9,10}
    };
    A[0].assign(0, 0);
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            cout << A[i][j] << endl;
        }
    }
    return 0;
}