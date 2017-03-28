#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

vector<vector<int> > comps; /* the comps itself*/
vector<int> compIndex, ind, lowLink;
stack<int> st;
vector<bool> inst;
vector<vector<int> > adj; /*The intial graph*/
vector<vector<int> > cmpAdj; /*The new graph between components*/
int idx = 0;
void init(int n) {
	adj.resize(n);
	cmpAdj.resize(n);
	idx = 0;
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
	}
	for (int i = 0; i < n; ++i) {
		cmpAdj[i].clear();
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
	for (int i = 0; i < sz(adj); i++)
		if (ind[i] == -1)
			tarjanSCC(i);
}
int in[100007];
void computeNewGraph() {
	cmpAdj.resize(sz(comps));
	for (int i = 0; i < sz(adj); i++) {
		for (int j = 0; j < sz(adj[i]); j++) {
			int k = adj[i][j];
			if (compIndex[k] != compIndex[i]) {
				cmpAdj[compIndex[i]].push_back(compIndex[k]);
				in[compIndex[k]]++;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		init(n);
		memset(in, 0, sizeof in);
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			y--;
			adj[x].push_back(y);
		}
		SCC();
		computeNewGraph();
		int ans = 0;
		for (int i = 0; i < sz(cmpAdj); ++i) {
			if (in[i] == 0)
				ans++;
		}
		printf("%d\n", ans);

	}

}

