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
	string line;
	vector<string> board;
	int N = 0;
	while (getline(cin, line)) board.push_back(line), N++;
	int M = sz(board[0]);
	int si, sj;
	int ei, ej;
	rep(i,0,N) rep(j,0,M) if (board[i][j] == 'S') si = i, sj = j, board[i][j] = 'a';
	rep(i,0,N) rep(j,0,M) if (board[i][j] == 'E') ei = i, ej = j, board[i][j] = 'z';
	int res = INT_MAX;
	rep(si,0,N) rep(sj,0,M) if (board[si][sj] == 'a') {
	queue<pii> q;
	q.push({si, sj});
	vector<vi> dist(N, vi(M, -1));
	dist[si][sj] = 0;
	const int DX[] = {0,0,1,-1};
	const int DY[] = {1,-1,0,0};
	while (!q.empty()) {
		pii pa = q.front();
		q.pop();
		rep(di,0,4) {
			int ni = pa.first + DX[di];
			int nj = pa.second + DY[di];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
			if (board[ni][nj] > board[pa.first][pa.second] + 1) continue;
			if (dist[ni][nj] != -1) continue;
			dist[ni][nj] = dist[pa.first][pa.second] + 1;
			q.push({ni, nj});
		}
	}
	// cout << dist[ei][ej] << endl;
	if (dist[ei][ej] != -1)
	res = min(res, dist[ei][ej]);
	}
	cout << res << endl;
}
