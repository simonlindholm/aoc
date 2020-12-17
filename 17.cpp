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
	vector<string> v;
	string x;
	while (cin >> x) v.push_back(x);
	int N = sz(v);
	int iters = 6;
	int pad = iters + 1;
	int M = N + 2*pad;

	vector<vector<vector<string>>> state(M, vector<vector<string>>(M, vector<string>(M, string(M, '.'))));
	vector<vector<vector<string>>> state2(M, vector<vector<string>>(M, vector<string>(M, string(M, '.'))));
	rep(i,0,N) rep(j,0,N) state[pad][pad][pad + i][pad + j] = v[i][j];

	rep(it,0,iters) {
		rep(l,1,M-1) rep(i,1,M-1) rep(j,1,M-1) rep(k,1,M-1) {
			int co = 0;
			rep(dw,-1,2) rep(dx,-1,2) rep(dy,-1,2) rep(dz,-1,2) 
				co += state[l + dw][i + dx][j + dy][k + dz] == '#';
			state2[l][i][j][k] = (state[l][i][j][k] == '#' ? (co == 3 || co == 4) : (co == 3)) ? '#' : '.';
		}
		state.swap(state2);
	}

	int res = 0;
	rep(l,1,M-1) rep(i,1,M-1) rep(j,1,M-1) rep(k,1,M-1) {
		if (state[l][i][j][k] == '#') res++;
	}
	cout << res << endl;
}
