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
	vi v;
	int x;
	while (cin >> x) v.push_back(x);
	int N = sz(v);
	rep(i,0,N) {
		ll sum = 0;
		int mi = INT_MAX, ma = INT_MIN;
		rep(j,i,N) {
			sum += v[j];
			ma = max(ma, v[j]);
			mi = min(mi, v[j]);
			if (sum == 177777905 && i != j) {
				cout << mi + ma << endl;
			}
		}
	}
	cout << "-" << endl;
	rep(i,25,N) {
		bool good = false;
		rep(j,0,25) rep(k,0,25) {
			if (v[i - j - 1] == v[i - k - 1]) continue;
			if (v[i - j - 1] + v[i - k - 1] == v[i]) good = true;
		}
		if (!good) {
			cout << v[i] << endl;
		}
	}
	exit(0);
}
