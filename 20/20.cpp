#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef uint64_t H;
H C = 1236862317235167231ULL;

int main() {
	vi v;
	string x;
	int id;
	char ch;
	vector<vector<string>> pieces;
	vi ids;
	while (cin >> x >> id >> ch) {
		vector<string> v;
		ids.push_back(id);
		rep(i,0,10) cin >> x, v.push_back(x);
		pieces.push_back(v);
	}
	int N = sz(pieces);
	vector<vector<vector<string>>> rotated(N);
	vector<array<H, 8>> edg(N);
	vector<array<H, 8>> redg(N);
	rep(i,0,N) {
		auto v = pieces[i];
		rotated[i].resize(8);
		rep(dir,0,8) {
			H ha = 1, har = 1;
			rep(i,0,10) ha = ha * C + v[0][i];
			rep(i,0,10) har = har * C + v[0][9-i];
			edg[i][dir] = ha;
			redg[i][dir] = har;
			rotated[i][dir] = v;
			auto w = v;
			rep(i,0,10) rep(j,0,10) w[i][j] = v[j][9-i];
			if (dir == 3) rep(i,0,10) rep(j,0,10) v[i][j] = w[j][i];
			else v = w;
		}
	}
	ll part1 = 1;
	int start = -1;
	vector<array<pii, 8>> conn(N);
	rep(i,0,N) {
		array<pii, 8> f = {{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}}};
		rep(d,0,8) {
			rep(j,0,N) if (i != j) rep(e,0,8) {
				if (edg[i][d] == redg[j][e]) {
					assert(f[d].first == -1);
					f[d] = pii(j, e);
				}
			}
		}
		int co = 0;
		rep(d,0,4) {
			if (f[d].first != -1) co++;
			// cout << i << ' ' << d << ' ' << j << ' ' << e << endl;
		}
		// cout << i << ' ' << co << endl;
		if (co == 2) {
			part1 *= ids[i]; // cout << i << endl;
			start = i;
		}
		conn[i] = f;
	}

	cout << part1 << endl;

	const int SIDE = (int)sqrt(N);
	vector<vector<pii>> grid(SIDE, vector<pii>(SIDE));
	int si = 0;
	while (!(conn[start][si].first == -1 && conn[start][(si - 1) & 3].first == -1)) si++;

	grid[0][0] = {start, si};
	auto rot90 = [](int d) {
		return (d&4) + ((d+1)&3);
	};
	rep(i,1,SIDE) {
		pii x = grid[0][i-1];
		pii y = conn[x.first][rot90(x.second)];
		y.second = rot90(y.second);
		grid[0][i] = y;
	}
	rep(i,1,SIDE) rep(j,0,SIDE) {
		pii x = grid[i-1][j];
		pii y = conn[x.first][rot90(rot90(x.second))];
		grid[i][j] = y;
	}

	/*
	rep(i,1,SIDE) {
		rep(j,0,SIDE) {
			cout << grid[i][j].first << ' ';
		}
		cout << endl;
	}
	return 0;
	*/

	const int S = SIDE * 8;
	vector<string> board(S, string(S, 'x'));
	rep(i,0,SIDE) rep(j,0,SIDE) {
		pii x = grid[i][j];
		auto g = rotated[x.first][x.second];
		rep(k,0,8) rep(l,0,8)
			board[i*8+k][j*8+l] = g[k+1][l+1];
	}

	/*
	rep(i,0,S) {
		rep(j,0,S) cout << board[i][j];
		cout << endl;
	}
	*/
	vector<string> pat = {
		"                  # ",
		"#    ##    ##    ###",
		" #  #  #  #  #  #   "
	};
	vector<vi> marked(S, vi(S));
	rep(dir,0,8) {
		rep(i,0,S) {
			rep(j,0,S) {
				rep(di,0,sz(pat)) rep(dj,0,sz(pat[0])) {
					int ni = i + di, nj = j + dj;
					if (ni >= S || nj >= S) goto fail;
					if (pat[di][dj] == ' ') continue;
					if (board[ni][nj] == '.') goto fail;
				}
				rep(di,0,sz(pat)) rep(dj,0,sz(pat[0])) {
					int ni = i + di, nj = j + dj;
					if (pat[di][dj] == ' ') continue;
					marked[ni][nj] = 1;
				}
fail:;
			}
		}

		vector<string> w(sz(pat[0]), string(sz(pat), 'x'));
		rep(i,0,sz(pat[0])) rep(j,0,sz(pat)) w[i][j] = pat[j][sz(pat[0])-1-i];
		pat = w;
		if (dir == 3) {
			vector<string> w(sz(pat[0]), string(sz(pat), 'x'));
			rep(i,0,sz(pat[0])) rep(j,0,sz(pat)) {
				w[i][j] = pat[j][i];
			}
			pat = w;
		}
	}
	int part2 = 0;
	rep(i,0,S) rep(j,0,S) if (board[i][j] == '#' && !marked[i][j]) part2++;
	cout << part2 << endl;
}
