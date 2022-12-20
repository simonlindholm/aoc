#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vi v;
	int x;
	list<pair<ll, int>> li;
	while (cin >> x) v.push_back(x), li.push_back({x, 0});
	int N = sz(v);
	{
	auto it = li.begin();
	rep(i,0,N) {
		while (it->second) ++it;
		ll by = it->first;
		it = li.erase(it);
		auto it2 = it;
		if (it2 == li.end()) it2 = li.begin();
		rep(c,0,by) {
			++it2;
			if (it2 == li.end()) it2 = li.begin();
		}
		rep(c,0,-by) {
			if (it2 == li.begin()) it2 = li.end();
			--it2;
		}
		li.insert(it2, {by, 1});
	}
	it = find(all(li), pair<ll, int>{0, 1});
	ll res = 0;
	rep(i,0,3) {
		rep(j,0,1000) {
			++it;
			if (it == li.end()) it = li.begin();
		}
		res += it->first;
	}
	cout << res << endl;
	}
	{
	li.clear();
	trav(x, v) li.push_back({x * 811589153LL, 0});
	auto it = li.begin();
	vector<list<pair<ll, int>>::iterator> its;
	rep(i,0,N) its.push_back(it++);
	rep(b,0,10) {
		rep(i,0,N) {
			auto it = its[i];
			ll by = it->first;
			ll orig = by;
			by %= N-1;
			it = li.erase(it);
			auto it2 = it;
			if (it2 == li.end()) it2 = li.begin();
			rep(c,0,by) {
				++it2;
				if (it2 == li.end()) it2 = li.begin();
			}
			rep(c,0,-by) {
				if (it2 == li.begin()) it2 = li.end();
				--it2;
			}
			its[i] = li.insert(it2, {orig, 1});
		}
	}
	it = find(all(li), pair<ll, int>{0, 1});
	ll res = 0;
	rep(i,0,3) {
		rep(j,0,1000) {
			++it;
			if (it == li.end()) it = li.begin();
		}
		res += it->first;
	}
	cout << res << endl;
}
}
