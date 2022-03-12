#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int X, A, B, C;
    cin >> X >> A >> B >> C;
    int i = 0;
    int key;
    while(true){
        if(i % 3 == 0){
            X -= A;
        }
        else if(i % 3 == 1){
            X -= B;
        }
        else{
            X -= C;
        }
        if(X < 0){
            key = i % 3;
            break;
        }
        i++;
    }
    if(key == 0){
        cout << 'F' << endl;
    }
    else if(key == 1){
        cout << 'M' << endl;
    }
    else{
        cout << 'T' << endl;
    }
    return 0;
}