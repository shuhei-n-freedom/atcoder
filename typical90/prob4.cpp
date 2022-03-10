#include<bits/stdc++.h>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<int> sumh(H, 0), sumw(W, 0);
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            sumh[i] += A[i][j];
        }
    }
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            sumw[i] += A[j][i];
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << sumh[i] + sumw[j] - A[i][j] << " "; 
        }
        cout << endl;
    }
}