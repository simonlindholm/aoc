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
	const int N = 1'000'000;
	list<int> s;
	string s2;
	cin >> s2;
	rep(i,0,sz(s2)) s.push_back(s2[i] - '0');
	rep(i,sz(s2),N) s.push_back(i + 1);
	vector<list<int>::iterator> its(N);
	for (auto it = s.begin(); it != s.end(); ++it) {
		its[*it - 1] = it;
	}
	rep(iteration,0,10'000'000) {
		auto it = s.begin();
		int start = *it;
		++it;
		vi t;
		rep(i,0,3) {
			t.push_back(*it);
			its[*it - 1] = s.end();
			s.erase(it++);
		}

		int target = start;
		for (;;) {
			target--;
			if (target == 0) target = N;
			if (its[target - 1] != s.end()) break;
		}
		auto it2 = its[target - 1];
		for (int x : t) {
			++it2;
			it2 = s.insert(it2, x);
			its[x - 1] = it2;
		}
		assert(*s.begin() == start);
		s.erase(s.begin());
		s.push_back(start);
		it = s.end();
		its[start - 1] = --it;
	}

	auto it = find(all(s), 1);
	vi shuf(s.begin(), it);
	s.erase(s.begin(), ++it);
	s.insert(s.end(), all(shuf));
	cout << (long long) *s.begin() * *(++s.begin()) << endl;
}
