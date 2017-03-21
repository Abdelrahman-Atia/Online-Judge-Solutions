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
bool vis[307][307];

int n;
bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
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
				if (valid(nx, ny) && !vis[nx][ny]){
					q.push(make_pair(nx, ny));
					vis[nx][ny] = 1;

				}
			}
		}

		++depth;
	}
	return -1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		int x, y, x1, y1;
		scanf("%d %d", &x, &y);
		scanf("%d %d", &x1, &y1);
		printf("%d\n", bfs(x, y, x1, y1));

	}

}
