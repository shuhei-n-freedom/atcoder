#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> plots(N);
    for(int i = 0; i < N; i++){
        cin >> plots[i].first >> plots[i].second;
    }
    double ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            double tmp = (plots[i].first - plots[j].first)*(plots[i].first - plots[j].first) + (plots[i].second - plots[j].second)*(plots[i].second - plots[j].second);
            ans = max(ans, tmp);
        }
    }
    cout << setprecision(10) << sqrt(ans) << endl;
    return 0;
}