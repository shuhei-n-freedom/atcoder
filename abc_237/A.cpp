#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main(){
    ll N;
    cin >> N;
    ll key = pow(2, 31);
    if(N < key && N >= -key){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}