#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>; 

int main(){
    double A, B;
    cin >> A >> B;
    double leng = sqrt(A*A + B*B);
    cout << setprecision(12) << A / leng << " " << setprecision(12) << B / leng << endl;
    return 0;
}