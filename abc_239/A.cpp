#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
int main(){
    int H;
    cin >> H;
    double ans = sqrt(H) * sqrt(12800000 + H);
    cout << setprecision(12) << ans << endl;
    return 0;
}