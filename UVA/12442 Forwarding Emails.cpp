#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int cnt[50007];
int vis[50007];

vector<vector<int> > SCCs /* The components itself*/;
#define comps SCCs
vector<int> compIndex /* for each node, what is the index of the component this node inside*/
, ind, lowLink;
stack<int> st;
vector<bool> inst;
vector<vector<int> > adj /*The intial graph*/;
int idx = 0; //must be intialized by zero;
void tarjanSCC(int i) {
	lowLink[i] = ind[i] = idx++;
	st.push(i);
	inst[i] = true;
	for (int j = 0; j < adj[i].size(); j++) {
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
			compIndex[n] = comps.size();
		}
		comps.push_back(comp);
	}
}
void SCC() {
	comps.clear();
	compIndex.resize(adj.size());
	ind.clear();
	ind.resize(adj.size(), -1);
	lowLink.resize(adj.size());
	inst.resize(adj.size());
	idx = 0; //must be intialized by zero;
	for (int i = 0; i < adj.size(); i++)
		if (ind[i] == -1)
			tarjanSCC(i);
}
vector<vector<int> > cmpAdj /*The new graph between components*/;
void computeNewGraph() {
	cmpAdj.resize(comps.size());
	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int k = adj[i][j];
			if (compIndex[k] != compIndex[i]) {
				cmpAdj[compIndex[i]].push_back(compIndex[k]);
			}
		}
	}
}
int dfs(int v) {
	vis[v] = 1;
	cnt[v] = sz(SCCs[v]);
	for (int i = 0; i < sz(cmpAdj[v]); ++i) {
		int u = cmpAdj[v][i];
		if (!vis[u])
			cnt[v] += dfs(u);
		else
			cnt[v] += cnt[u];
	}
	return cnt[v];
}
int main() {
	int t;
	cin >> t;
	for (int ts = 1; ts <= t; ++ts) {
		adj.clear();
		cmpAdj.clear();
		SCCs.clear();
		compIndex.clear();
		inst.clear();

		idx = 0;
		int n;
		int x, y;
		memset(vis, 0, sizeof vis);
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);
		adj.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &x, &y);
			x--;
			y--;
			adj[x].push_back(y);
		}
		SCC();
		computeNewGraph();
		int mx = -1;
		int mn = 100000;
		for (int i = 0; i < sz(cmpAdj); ++i) {
			int ans = vis[i] ? cnt[i] : dfs(i);
			if (ans > mx) {
				mx = ans;
				mn = 100000;
				for (int j = 0; j < sz(SCCs[i]); ++j) {
					if (SCCs[i][j] < mn)
						mn = SCCs[i][j];
				}
			} else if (ans == mx) {
				for (int j = 0; j < sz(SCCs[i]); ++j) {
					if (SCCs[i][j] < mn)
						mn = SCCs[i][j];
				}
			}

		}
		printf("Case %d: ", ts);
		cout << mn + 1 << endl;

	}

}
