#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using Graph = vector<vector<int>>;
//桁dp
map<pair<ll, ll>, bool> mp;
bool func(ll a, ll s){
    if(!s){
        return a==0;
    }
    pair<int, int> p = make_pair(a, s);
    /*
    if(mp.count(p)){
        return mp[p];
    }
    */
    for(int x = 0; x < 2; x++){
        for(int y = 0; y < 2; y++){
            if((x&y) != (a&1)) continue;
            if((s - x - y) < 0) continue;
            if((s - x - y) % 2 != 0) continue;
            if(func(a>>1, (s - x - y)>>1)){
                return mp[p] = true;
            }
        }
    }
    return mp[p] = false;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        ll a, s;
        cin >> a >> s;
        mp = map<pair<ll, ll>, bool>();
       if(func(a, s)){
           cout << "Yes" << endl;
       }
       else{
           cout << "No" << endl;
       }
    }
    return 0;
}