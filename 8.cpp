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
	string inst;
	int off;
	vector<pair<string, int>> instr;
	while (cin >> inst >> off) {
		instr.push_back({inst, off});
	}

	int N = sz(instr);
	rep(i,0,N) {
		int at = 0;
		int acc = 0;
		vi seen(N);
		for (;;) {
			if (at == N) {
				// part 2
				cout << acc << endl;
				return 0;
			}

			if (seen[at]++) {
				break;
				// part 1
				// cout << acc << endl;
				// return 0;
			}
			auto &s = instr[at].first;
			if (s == "nop" || (s == "jmp" && i == at)) at++;
			else if (s == "jmp" || (s == "nop" && i == at)) at += instr[at].second;
			else if (s == "acc") acc += instr[at].second, at++;
		}
	}
	exit(0);
}
