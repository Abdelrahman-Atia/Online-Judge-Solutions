#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
bool vis[10000];
vector<int> incs;
int bfs(int a, int g) {
	memset(vis, 0, sizeof vis);
	int depth = 0;
	queue<int> q;
	q.push(a);
	vis[a] = 1;
	while (!q.empty()) {
		int SZ = sz(q);
		while (SZ--) {

			int x = q.front();

			q.pop();

			if (x == g)
				return depth;
			for (auto inc : incs) {
				int nx = x + inc;
				nx %= 10000;
				if (!vis[nx]) {
					q.push(nx);
					vis[nx] = 1;
				}
			}

		}

		++depth;
	}
	return -1;
}

int main() {
	int a, g, d;
	scanf("%d %d %d" , &a , &g , &d);
	int ts = 1;
	while(1)
	{
		if(a  == 0 && g == 0 && d == 0)break;
		incs.clear();
		incs.resize(d);
		for (int i = 0; i < d; ++i) {
			scanf("%d" , &incs[i]);
		}
		printf("Case %d: " , ts);
		ts++;
		int ans = bfs(a , g);
		if(ans == -1)puts("Permanently Locked");
		else
			cout << ans << endl;
		scanf("%d %d %d" , &a , &g , &d);
	}

}
