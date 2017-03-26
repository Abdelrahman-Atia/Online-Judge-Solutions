#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

int adj[20][20];

int yes = 0;
int vis[17];
int n;
void dfs(int u, string ans) {
	if (u == 0 && sz(ans) == n+2) {
		yes = 1;
		return;
	}
	if (u == 0 && sz(ans) > 1)
		return;

	for (int v = 0; v <= n; v++) {
		if (adj[u][v] && !vis[v]) {
			vis[v] = 1;
			dfs(v, ans + char(v + '0'));
			vis[v] = 0;
		}
	}

}
int main() {
	int ts = 1;
	while (scanf("%d" , &n) == 1) {
		if (n == 0)
			break;

		memset(vis, 0, sizeof vis);
		memset(adj, 0, sizeof adj);

		yes = 0;
		getchar();

		for (int i = 1; i <= n; ++i) {
			char c;

			while ((c = getchar()) && c != '\n') {
				if (isdigit(c)) {
					adj[i][c - '0'] = adj[c - '0'][i]  = 1;
 				}
			}
		}
		dfs(0, "0");
		if (yes)
			printf("Case %d: Granny can make the circuit.\n", ts);
		else
			printf("Case %d: Granny can not make the circuit.\n", ts);
		ts++;

	}
}

