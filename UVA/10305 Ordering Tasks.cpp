#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
vector<vector<int> > adj;
const int MX = 107;
int in[MX];

int main() {
	int n, m;
	cin >> n >> m;
	while (1) {
		if(n+m == 0)return 0;
		adj.resize(n);
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			y--;
			in[y]++;
			adj[x].push_back(y);
		}
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (in[i] == 0)
				q.push(i);
		}
		vector<int> ans;
		while (!q.empty()) {
			int tp = q.front();
			q.pop();
			ans.push_back(tp);
			for (auto v : adj[tp]) {
				in[v]--;
				if (in[v] == 0)
					q.push(v);
			}
		}
		for (int i = 0; i < sz(ans); ++i) {
			cout << ans[i] + 1;
			if (i == sz(ans) - 1)
				puts("");
			else
				printf(" ");
		}
		scanf("%d %d" , &n , &m);
	}
}
