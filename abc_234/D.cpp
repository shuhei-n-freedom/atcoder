#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < K; i++){
        pq.push(P[i]);
    }
    cout << pq.top() << endl;
    for(int i = K; i < N; i++){
        if(pq.top() < P[i]){
            pq.pop();
            pq.push(P[i]);
        }
        cout << pq.top() << endl;
    }
    return 0;
}