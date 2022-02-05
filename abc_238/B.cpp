#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using Graph = vector<vector<int>>;

int main(){
    int N;
    cin >> N;
    vi deg;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    deg.push_back(360);
    deg.push_back(0);
    int degree = 0;
    for(int i = 0; i < N; i++){
        degree += A[i];
        deg.push_back(degree%360);
    }
    sort(deg.begin(), deg.end());
    int ans = 0;
    for(int i = 0; i < deg.size() - 1; i++){
        ans = max(ans, deg[i + 1] - deg[i]);
    }
    cout << ans << endl;
    return 0;
}