#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int part1(deque<int> a, deque<int> b) {
	while (!a.empty() && !b.empty()) {
		int x = a.front(), y = b.front();
		a.pop_front();
		b.pop_front();
		if (x > y) {
			a.push_back(x);
			a.push_back(y);
		} else {
			b.push_back(y);
			b.push_back(x);
		}
	}

	if (a.empty()) swap(a, b);
	int res = 0;
	rep(i,0,sz(a)) {
		res += a[i] * (sz(a) - i);
	}
	return res;
}

pair<int, int> part2(deque<int> a, deque<int> b) {
	map<pair<deque<int>, deque<int>>, int> seen;

	int winner;
	for (;;) {
		if (a.empty()) {
			winner = 1;
			break;
		}
		if (b.empty()) {
			winner = 0;
			break;
		}
		if (seen[{a,b}]++) {
			winner = 0;
			break;
		}
		int x = a.front(), y = b.front();
		a.pop_front();
		b.pop_front();
		bool awin = (x > y);
		if (x <= sz(a) && y <= sz(b)) {
			deque<int> asub(a.begin(), a.begin() + x), bsub(b.begin(), b.begin() + y);
			awin = part2(asub, bsub).first == 0;
		}
		if (awin) {
			a.push_back(x);
			a.push_back(y);
		} else {
			b.push_back(y);
			b.push_back(x);
		}
	}

	if (winner == 1) swap(a, b);

	int res = 0;
	rep(i,0,sz(a)) {
		res += a[i] * (sz(a) - i);
	}
	return {winner, res};
}

int main() {
	deque<int> a, b;
	string s;
	getline(cin, s);
	int x;
	while (cin >> x)
		a.push_back(x);
	cin.clear();
	cin >> s;
	getline(cin, s);
	while (cin >> x)
		b.push_back(x);

	cout << part1(a, b) << endl;
	cout << part2(a, b).second << endl;
}
