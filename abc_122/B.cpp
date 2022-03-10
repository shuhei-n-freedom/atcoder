#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans = 0;
    for(int i = 0; i < S.size(); i++){
        for(int j = i; j < S.size(); j++){
            string scut = S.substr(i, j + 1 - i);
            bool check = true;
            for(int k = 0; k < scut.size(); k++){
                if(!(scut[k] == 'A' || scut[k] == 'C' || scut[k] == 'G' || scut[k] == 'T')){
                    check = false;
                }
            }
            if(check){
                int tmp = scut.size();
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}