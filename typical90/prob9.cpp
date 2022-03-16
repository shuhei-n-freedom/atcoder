#include<bits/stdc++.h>
using namespace std;
// okurairi
double getangle(double a, double b){
    double ret = abs(a - b);
    if(ret >= 180){
        return 360.0 - ret;
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    vector<pair<double, double>> P(N);
    for(int i = 0; i < N; i++){
        cin >> P[i].first >> P[i].second;
    }
    double ans = 0;
    for(int i = 0; i < N; i++){
        ans = 0.0;
        vector<double> degs;
        for(int j = 0; j < N; j++){
            if(i == j){
                continue;
            }
            double x, y;
            x = P[j].first - P[i].first;
            y = P[j].second - P[i].second;
            double ang;
            double leng_hyp = sqrt(x * x + y * y);
            if(y >= 0){
                ang = acos(leng_hyp) * 180.0 / 3.14159265358979;
            }
            else{
                ang = 360.0 - acos(leng_hyp) * 180.0 / 3.14159265358979;
            }
            degs.push_back(ang);
        }
        sort(degs.begin(), degs.end());
        double ang2 = 0.0;
        for(int j = 0; j < degs.size(); j++){
            double tar = (degs[j] + 180.0);
            if(tar >= 360.0){
                tar -= 360.0;
            }
            int tmp = lower_bound(degs.begin(), degs.end(), tar) - degs.begin();
            int point1 = tmp % degs.size();
            int point2 = (tmp + degs.size() - 1) % degs.size();
            double cand1 = getangle(degs[j], degs[point1]);
            double cand2 = getangle(degs[j], degs[point2]);
            ang2 = max(ang2, cand1);
            ang2 = max(ang2, cand2);
        }
        ans = max(ans, ang2);
    }
    cout << ans << endl;
    return 0;
}