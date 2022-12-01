#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	vector<string> v;
	string x;
	while (cin >> x) x = "x" + x + "x", v.push_back(x);
	int N = sz(v);
	int M = sz(v[0]);
	v.push_back(string(M, 'x'));
	v.insert(v.begin(), string(M, 'x'));
	N += 2;
	for (;;) {
		vector<string> w = v;
		rep(i,1,N-1) rep(j,1,M-1) {
			if (v[i][j] == '.') continue;
			int occ = 0;
			rep(di,-1,2) rep(dj,-1,2) if (di || dj) {
				rep(k,1,100000) {
					int ni = i + di*k;
					int nj = j + dj*k;
					if (v[ni][nj] == '.') continue;
					occ += v[ni][nj] == '#';
					break;
				}
			}
			if (v[i][j] == '#') {
				w[i][j] = occ >= 5 ? 'L' : '#';
			} else {
				w[i][j] = occ >= 1 ? 'L' : '#';
			}
		}
		if (v == w) break;
		v = w;
	}
	int res = 0;
	rep(i,1,N-1) rep(j,1,M-1) {
		if (v[i][j] == '#') res++;
	}
	cout << res << endl;
}
