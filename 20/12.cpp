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
	char dir;
	int amt;
	int x = 10, y = 1;
	int ang = 0;
	ll sx = 0, sy = 0;
	while (cin >> dir >> amt) {
		if (dir == 'F') {
			// dir = "ESWN"[ang & 3];
			sx += (ll)x * amt;
			sy += (ll)y * amt;
		}

		if (dir == 'N') y += amt;
		else if (dir == 'S') y -= amt;
		else if (dir == 'W') x -= amt;
		else if (dir == 'E') x += amt;
		else if (dir == 'L') {
			// ang -= amt / 90;
			amt /= 90;
			rep(i,0,amt) {
				int ny = y;
				y = x;
				x = -ny;
			}
		}
		else if (dir == 'R') {
			// ang += amt / 90;
			amt /= 90;
			rep(i,0,amt*3) {
				int ny = y;
				y = x;
				x = -ny;
			}
		}
	}
	// cout << abs(x) + abs(y) << endl;
	cout << abs(sx) + abs(sy) << endl;
}
