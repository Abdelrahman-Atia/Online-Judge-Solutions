#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

vector<vector<int> > SCCs;
#define comps SCCs
vector<int> compIndex, ind, lowLink;
stack<int> st;
vector<bool> inst;
vector<vector<int> > adj;
int idx = 0;
void init(int n) {
	adj.resize(n);
	idx = 0;
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
	}
}
void tarjanSCC(int i) {
	lowLink[i] = ind[i] = idx++;
	st.push(i);
	inst[i] = true;
	for (int j = 0; j < sz(adj[i]); j++) {
		int k = adj[i][j];
		if (ind[k] == -1) {
			tarjanSCC(k);
			lowLink[i] = min(lowLink[i], lowLink[k]);
		} else if (inst[k]) {
			lowLink[i] = min(lowLink[i], lowLink[k]);
		}
	}
	if (lowLink[i] == ind[i]) {
		vector<int> comp;
		int n = -1;
		while (n != i) {
			n = st.top();
			st.pop();
			comp.push_back(n);
			inst[n] = 0;
			compIndex[n] = sz(comps);
		}
		comps.push_back(comp);
	}
}
void SCC() {
	comps.clear();
	compIndex.resize(sz(adj));
	ind.clear();
	ind.resize(sz(adj), -1);
	lowLink.resize(sz(adj));
	inst.resize(sz(adj));
	idx = 0;
	for (int i = 0; i < sz(adj); i++)
		if (ind[i] == -1)
			tarjanSCC(i);
}

int yes = true;
int vis[10007];
void dfs(int u) {
	vis[u] = 1;
	for (auto v : adj[u]) {
		if (!vis[v])
			dfs(v);
		else if (vis[v] == 2)
			yes = false;
	}
	vis[u] = 2;
}
int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		memset(vis, 0, sizeof vis);
		yes = true;
		init(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
		}
		SCC();
		if (sz(SCCs) != 1) {
			puts("NO");
			continue;
		}
		dfs(0);
		if(yes)puts("YES");
		else puts("NO");

	}
}
