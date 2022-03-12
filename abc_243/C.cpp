#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector<pair<pair<ll, ll>, int>> P(N);
    for(int i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        P[i] = make_pair(make_pair(y, x), i);
    }
    string S;
    cin >> S;
    sort(P.begin(), P.end());
    ll key = 0;
    /*
    for(int i = 0; i < N; i++){
        cout << P[i].first.first << " " << P[i].first.second << P[i].second << endl;
    }
    */
    pair<ll, ll> keypos;
    bool check = false;
    for(int i = 0; i < N; i++){
        
    }
    if(check){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}