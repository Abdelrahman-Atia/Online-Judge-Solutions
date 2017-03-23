#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
map<int, pair<int, int> > d;
string a[107];
int n, m;
int turnleft(int x) {
	if (x == 0)
		return 3;
	return x - 1;

}
int turnright(int x) {
	if (x == 3)
		return 0;
	return x + 1;
}
bool valid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 0;
	return a[x][y] != '#';
}
int main() {
	d[0] = make_pair(-1, 0); //up
	d[1] = make_pair(0, 1); //right
	d[2] = make_pair(1, 0); //down
	d[3] = make_pair(0, -1); //left
	int s;
	scanf("%d %d %d", &n, &m, &s);
	while (1) {
		if (!n && !m && !s)
			break;
		int x, y, dir;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == 'N' || a[i][j] == 'S' || a[i][j] == 'L'
						|| a[i][j] == 'O') {
					x = i;
					y = j;
					if (a[i][j] == 'N')
						dir = 0;
					if (a[i][j] == 'L')
						dir = 1;
					if (a[i][j] == 'S')
						dir = 2;
					if (a[i][j] == 'O')
						dir = 3;
					a[i][j] = '.';
				}
			}
		}
		string sq;
		cin >> sq;

		int ans = 0;
		for (int i = 0; i < s; ++i) {

			if (sq[i] == 'D') //right
				dir = turnright(dir);
			else if (sq[i] == 'E') //left
				dir = turnleft(dir);
			else if (sq[i] == 'F') {
				int nx = x + d[dir].fr;
				int ny = y + d[dir].sc;
				if (valid(nx, ny)) {
					x = nx;
					y = ny;
				}
			}

			if (a[x][y] == '*') {
				ans++;
				a[x][y] = '.';
			}
		}

		cout << ans << endl;

		scanf("%d %d %d", &n, &m, &s);
	}

}
