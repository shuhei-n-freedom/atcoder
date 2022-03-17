#include<bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    int K;
    cin >> K;
    vector<vector<char> > a(H, vector<char>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> a[i][j];

    vector<vector<int> > J(H+1, vector<int>(W+1, 0));
    vector<vector<int> > O(H+1, vector<int>(W+1, 0));
    vector<vector<int> > I(H+1, vector<int>(W+1, 0));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) {
        //s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];
        if(a[i][j] == 'J'){
            J[i + 1][j + 1] = J[i][j + 1] + J[i + 1][j] - J[i][j] + 1;
            O[i + 1][j + 1] = O[i][j + 1] + O[i + 1][j] - O[i][j];
            I[i + 1][j + 1] = I[i][j + 1] + I[i + 1][j] - I[i][j];
        }
        if(a[i][j] == 'O'){
            J[i + 1][j + 1] = J[i][j + 1] + J[i + 1][j] - J[i][j];
            O[i + 1][j + 1] = O[i][j + 1] + O[i + 1][j] - O[i][j] + 1;
            I[i + 1][j + 1] = I[i][j + 1] + I[i + 1][j] - I[i][j];
        }
        if(a[i][j] == 'I'){
            J[i + 1][j + 1] = J[i][j + 1] + J[i + 1][j] - J[i][j];
            O[i + 1][j + 1] = O[i][j + 1] + O[i + 1][j] - O[i][j];
            I[i + 1][j + 1] = I[i][j + 1] + I[i + 1][j] - I[i][j] + 1;
        }
    }

    for (int q = 0; q < K; ++q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        cout << J[c][d] - J[c][b] - J[a][d] + J[a][b] << " ";
		cout << O[c][d] - O[c][b] - O[a][d] + O[a][b] << " ";
		cout << I[c][d] - I[c][b] - I[a][d] + I[a][b] << endl;
    }
    return 0;
}   