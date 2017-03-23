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
int dx2[] = { 2, 2, -2, -2 };
int dy2[] = { 2, -2, -2, 2 };

int n;
bool op[50][50];
bool vis[50][50][5];
int mirr(int x) {
	return n - x + 1;
}
bool valid(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > n)
		return 0;
	return !op[x][y];
}
int bfs(int sx, int sy, int Dx, int Dy) {
	queue<pair<int, pair<int, int>> > q;
	int depth = 0;
	vis[sx][sy][1] = 1;
	vis[sx][sy][2] = 1;
	vis[sx][sy][3] = 1;
	q.push(make_pair(sx, make_pair(sy , -1)));

	while (!q.empty()) {
		int SZ = sz(q);
		while (SZ--) {
			int x = q.front().fr;
			int y = q.front().sc.fr;
			int typ = q.front().sc.sc;
			q.pop();

			if (x == Dx && y == Dy)
				return depth;
			if (typ != 1) {
				for (int i = 0; i < 8; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (valid(nx, ny) && !vis[nx][ny][1]) {
						q.push(make_pair(nx, make_pair(ny, 1)));
						vis[nx][ny][1] = 1;
					}
				}
			}
			if (typ != 2) {
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx2[i];
					int ny = y + dy2[i];
					if (valid(nx, ny) && !vis[nx][ny][2]) {
						q.push(make_pair(nx, make_pair(ny, 2)));
						vis[nx][ny][2] = 1;
					}
				}
			}
			if (typ != 3) {
				int nx = mirr(x);
				int ny = y;
				if (valid(nx, ny) && !vis[nx][ny][3]) {
					q.push(make_pair(nx, make_pair(ny , 3)));
					vis[nx][ny][3] = 1;
				}
				nx = x;
				ny = mirr(y);
				if (valid(nx, ny) && !vis[nx][ny][3]) {
					q.push(make_pair(nx, make_pair(ny , 3)));
					vis[nx][ny][3] = 1;
				}
			}
		}

		depth++;
	}
	return -1;

}
int main() {
	scanf("%d", &n);
	while (n) {
		memset(op, 0, sizeof op);
		memset(vis, 0, sizeof vis);
		if (!n)
			break;
		n *= 2;
		int sx, sy;
		scanf("%d %d", &sx, &sy);
		int Dx, Dy;
		scanf("%d %d", &Dx, &Dy);
		int opx, opy;
		scanf("%d %d", &opx, &opy);
		while (1) {
			if (opx == 0)
				break;
			op[opx][opy] = 1;
			scanf("%d %d", &opx, &opy);
		}
		int ans = bfs(sx, sy, Dx, Dy);
		if (ans == -1)
			puts("Solution doesn't exist");
		else
			printf("Result : %d\n", ans);

		scanf("%d", &n);

	}

}
