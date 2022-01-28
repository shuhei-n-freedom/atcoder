#include<bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    for(int i = 0; i < H; i++){
        cin >> field[i];
    }
    vector<vector<int>> points(H + 1, vector<int>(W + 1));
    for(int i = H - 1; i >= 0; i--){
        for(int j = W - 1; j >= 0; j--){
            if(field[i][j] ==  '#'){
                continue;
            }
            points[i][j] = max(points[i + 1][j], points[i][j + 1]) + 1;
        }
    }
    cout << points[0][0] << endl;
    return 0;
}