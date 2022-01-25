#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string tobinary(ll s){
    string r;
    while (s != 0){
        r += '0' + (s % 2);
        s /= 2;
    }
    return r;
}

int main(){
    ll s;
    cin >> s;
    string ans = tobinary(s);
    reverse(ans.begin(), ans.end());
    
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == '0'){
            cout << ans[i];
        }
        else{
            cout << '2';
        }
    }
    cout << endl;
    return 0;
}