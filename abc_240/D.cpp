#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int count = 0;
    stack<pair<int, int>> S;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        count += 1;
        if(S.size() == 0 || S.top().first != a){
            S.push(make_pair(a, 1));
        }
        else{
            S.top().second += 1;
            if(S.top().second == a){
                count -= a;
                S.pop();
            }
        }
        cout << count << endl;
    }
    return 0;
}