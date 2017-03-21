#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int dx[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dy[] = { 1, -1, 1, -1, 2, 2, -2, -2 };
bool vis[10][10];
int dist[10][10][10][10];
string gd[8];
bool valid(int x, int y) {
	if (!(x >= 0 && x < 8 && y >= 0 && y < 8))
		return 0;
	return (gd[x][y] != 'K' && gd[x][y] != 'p');
}
int bfs(int a, int b, int g1, int g2) {
	memset(vis, 0, sizeof vis);
	int depth = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	vis[a][b] = 1;
	while (!q.empty()) {
		int SZ = sz(q);
		while (SZ--) {

			int x = q.front().fr;
			int y = q.front().sc;

			q.pop();

			if (x == g1 && y == g2)
				return depth;

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (valid(nx, ny) && !vis[nx][ny]) {
					q.push(make_pair(nx, ny));
					vis[nx][ny] = 1;

				}
			}
		}

		++depth;
	}
	return -1;
}//P p P
vector<pair<int, int> > nod;
int dp[10][10][600];
int solve(int x, int y, int mask) {
	if (mask == (1 << sz(nod)) - 1)
		return 0;
	int &ret = dp[x][y][mask];
	if (ret + 1)
		return ret;
	ret = 1e9;
	for (int i = 0; i < sz(nod); ++i) {
		if (mask & (1 << i))
			continue;
		int x1 = nod[i].fr;
		int y1 = nod[i].sc;
		ret = min(ret, dist[x][y][x1][y1] + solve(x1, y1, mask | (1 << i)));
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(dist, 0, sizeof dist);
		nod.clear();
		int n;
		scanf("%d", &n);
		int x, y;
		int idx;
		for (int i = 0; i < 8; ++i) {
			cin >> gd[i];
			for (int j = 0; j < 8; ++j) {
				if (gd[i][j] == 'k') {
					x = i, y = j;
					idx = sz(nod);
					nod.push_back(make_pair(i, j));
				}
				if (gd[i][j] == 'P')
					nod.push_back(make_pair(i, j));
			}
		}
		for (int i = 0; i < sz(nod); ++i) {
			int x1 = nod[i].fr;
			int y1 = nod[i].sc;
			for (int j = i + 1; j < sz(nod); ++j) {
				int x2 = nod[j].fr;
				int y2 = nod[j].sc;
				dist[x1][y1][x2][y2] = dist[x2][y2][x1][y1] = bfs(x1, y1, x2,
						y2);
			}
		}
		memset(dp, -1, sizeof dp);
		int ans = solve(x, y, 1 << idx);
		//cout << ans << endl;
		if (ans <= n)
			puts("Yes");
		else
			puts("No");

	}

}
