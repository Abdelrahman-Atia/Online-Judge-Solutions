#include <algorithm>
#include <queue>
#include <vector>
#include<iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int dx[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dy[] = { 1, -1, 1, -1, 2, 2, -2, -2 };
int vis[10][10];
//97
//122
bool valid(int x, int y) {
	return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
}
int bfs(int a, int b, int g1, int g2) {
	memset(vis, 0, sizeof vis);
	int depth = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int SZ = sz(q);
		while (SZ--) {
			int x = q.front().fr;
			int y = q.front().sc;
			q.pop();
			vis[x][y] = 1;
			if (x == g1 && y == g2)
				return depth;

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (valid(nx, ny) && !vis[nx][ny])
					q.push(make_pair(nx, ny));
			}
		}
		++depth;
	}
	return -1;
}
int main() {
	string a, b;
	while (cin >> a >> b) {
		int x = a[0] - 'a';
		int y = a[1] - '1';
		int x1 = b[0] - 'a';
		int y1 = b[1] - '1';
		int ans = bfs(x , y , x1 , y1);
		printf("To get from %s to %s takes %d knight moves.\n" , a.c_str() , b.c_str() , ans);

	}

}
