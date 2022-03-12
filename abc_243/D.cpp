#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    ll X;
    string S;
    cin >> N >> X >> S;
    ll cal = 0, cal2 = 0; 
    for(int i = 0; i < N; i++){
        if(S[i] == 'U'){
            cal--;
            cal2 /= 2;
        }
        else if(S[i] == 'L'){
            cal++;
            cal2 *= 2;
        }
        else{
            cal++;
            cal2 *= 2;
            cal2++;
        }

    }
    cout << setprecision(18) << X * pow(2, cal) + cal2 << endl;
    return 0;
}