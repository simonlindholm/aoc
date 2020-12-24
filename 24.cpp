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
	map<pii, int> vals;
	string s;
	while (cin >> s) {
		int x = 0, y = 0;
		rep(i,0,sz(s)) {
			char c = s[i];
			if (c == 'n' || c == 's') {
				i++;
				char d = s[i];
				if (c == 'n') y++, x--; else y--;
				x += (d == 'e' ? 1 : 0);
			} else {
				x += (c == 'e' ? 1 : -1);
			}
		}
		vals[pii(x,y)] ^= 1;
	}

	int part1 = 0;
	trav(pa, vals) part1 += pa.second;
	cout << part1 << endl;

	rep(it,0,100) {
		map<pii, pii> adj;
		trav(pa, vals) if (pa.second) {
			int x = pa.first.first, y = pa.first.second;
			int DX[] = {-1,1,1,0,0,-1};
			int DY[] = {0,0,-1,-1,1,1};
			rep(d,0,6) adj[pii(x + DX[d], y + DY[d])].first++;
			adj[pii(x,y)].second = 1;
		}
		map<pii, int> vals2;
		trav(pa, adj) {
			int co = pa.second.first;
			int mid = pa.second.second;
			if (co == 2 || (mid && co == 1))
				vals2[pa.first] = 1;
		}
		vals.swap(vals2);
	}

	int part2 = 0;
	trav(pa, vals) part2 += pa.second;
	cout << part2 << endl;
}
