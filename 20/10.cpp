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
	v.push_back(0);
	sort(all(v));
	int N = sz(v);
	v.push_back(v.back() + 3);
	/*
	int one = 0, three = 0;
	rep(i,0,N) {
		int d = v[i+1] - v[i];
		if (d == 1) one++;
		else if (d == 3) three++;
	}
	cout << one * three << endl;
	*/
	vector<ll> dp(v.back() + 3);
	dp[2] = 1;
	rep(i,1,sz(v)) {
		int x = v[i];
		dp[x + 2] = dp[x + 1] + dp[x - 0] + dp[x - 1];
	}
	cout << dp.back() << endl;
	exit(0);
}
