/*
#include<bits/stdc++.h>
using namespace std;

int H, W, Q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<bool>> used(2010, vector<bool>(2010));
struct unionfind{
    vector<int> par;

    unionfind(int N) : par(N){
        for(int i = 0; i < N; i++){
            par[i] = i;
        }
    }
    int root(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = root(par[x]);
    }
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return;
        }
        par[rx] = ry;
    }
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

void func1(int x, int y, vector<vector<bool>>& used, unionfind& u){
    for(int i = 0; i < 4; i++){
        int tmpx = x + dx[i];
        int tmpy = y + dy[i];
        if(tmpx < 0 || tmpy < 0){
            continue;
        }
        if(used[tmpx][tmpy] == false){
            continue;
        }
        int hash1 = (x - 1) * W + (y - 1);
        int hash2 = (tmpx - 1) * W + (tmpy - 1);
        u.unite(hash1, hash2);
    }
    used[x][y] = true;
}

bool func2(int x1, int y1, int x2, int y2, vector<vector<bool>>& used, unionfind& u){
    if(used[x1][y1] == false || used[x2][y2] == false){
        return false;
    }
    int hash1 = (x1 - 1) * W + (y1 - 1);
    int hash2 = (x2 - 1) * W + (y2 - 1);
    if(u.same(hash1, hash2) == true){
        return true;
    }
    return false;
}

int main(){
    cin >> H >> W >> Q;
    unionfind u(H * W);
    vector<vector<bool>> used(H, vector<bool>(W));
    for(int i = 0; i < Q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int x, y;
            cin >> x >> y;
            func1(x, y, used, u);
        }
        else{
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bool check = func2(x1, y1, x2, y2, used, u);
            if(check){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
*/
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
	vector<int> par;

	void init(int sz) {
		par.resize(sz, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

// 入力
int H, W, Q;

// その他の変数
UnionFind UF;
bool used[2009][2009];

void query1(int px, int py) {
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < 4; i++) {
		int sx = px + dx[i], sy = py + dy[i];
		if (used[sx][sy] == false) continue;
		int hash1 = (px - 1) * W + (py - 1);
		int hash2 = (sx - 1) * W + (sy - 1);
		UF.unite(hash1, hash2);
	}
	used[px][py] = true;
}

bool query2(int px, int py, int qx, int qy) {
	if (used[px][py] == false || used[qx][qy] == false) {
		return false;
	}

	int hash1 = (px - 1) * W + (py - 1);
	int hash2 = (qx - 1) * W + (qy - 1);
	if (UF.same(hash1, hash2) == true) return true;
	return false;
}

int main() {
	// Step #1. 入力
	cin >> H >> W >> Q;

	// Step #2. Union Find の初期化
	UF.init(H * W);

	// Step #3. クエリ処理
	for (int i = 1; i <= Q; i++) {
		int ty; cin >> ty;
		if (ty == 1) {
			int x, y;
			cin >> x >> y;
			query1(x, y);
		}
		if (ty == 2) {
			int xa, xb, ya, yb;
			cin >> xa >> ya >> xb >> yb;
			bool Answer = query2(xa, ya, xb, yb);
			if (Answer == true) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}