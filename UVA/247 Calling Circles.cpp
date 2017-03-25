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
vector<vector<int> > cmpAdj; /*The new graph between components*/
void computeNewGraph() {
	cmpAdj.resize(sz(comps));
	for (int i = 0; i < sz(adj); i++) {
		for (int j = 0; j < sz(adj[i]); j++) {
			int k = adj[i][j];
			if (compIndex[k] != compIndex[i]) {
				cmpAdj[compIndex[i]].push_back(compIndex[k]);
			}
		}
	}
}
map<string, int> idxs;
map<int, string> name;
int last = 0;

int main() {
	int n, m;
	bool nw = false;
	int ts = 1;
	while (cin >> n >> m) {
		if (n + m == 0)
			break;
		init(n);
		last = 0;
		idxs.clear();
		name.clear();
		for (int i = 0; i < m; ++i) {
			string x, y;
			cin >> x >> y;
			if (idxs.count(x) == 0) {
				idxs[x] = last;
				name[last] = x;
				last++;
			}

			if (idxs.count(y) == 0) {
				idxs[y] = last;
				name[last] = y;
				last++;
			}
			adj[idxs[x]].push_back(idxs[y]);
		}
		SCC();
		if (nw)
			puts("");
		nw = true;
		printf("Calling circles for data set %d:\n", ts);
		ts++;
		for (int i = 0; i < sz(SCCs); ++i) {
			for (int j = 0; j < sz(SCCs[i]); ++j) {
				cout << name[SCCs[i][j]];
				if (j == sz(SCCs[i]) - 1)
					puts("");
				else
					printf(", ");
			}
		}

	}
}
