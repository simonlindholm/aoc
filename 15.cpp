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
	vi v;
	int x;
	while (cin >> x) v.push_back(x), cin.ignore();
	int N = sz(v);
	vector<int> pos(30000000 + 10);
	rep(i,0,N) pos[v[i]] = i + 1;
	x = v[N-1];
	rep(i,N,30000000) {
		int p = pos[x];
		pos[x] = i;
		x = (p == 0 ? 0 : i - p);
	}
	cout << x << endl;
}
