#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

map<pair<int, int>, int> mp;

int par[10007]; //set to -1
int root(int v) {
	return par[v] < 0 ? v : (par[v] = root(par[v]));
}
void merge(int x, int y) {	//	x and y are some tools (vertices)
	if ((x = root(x)) == (y = root(y)))
		return;
	if (par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
int main() {
	int n;
	while (cin >> n) {
		mp.clear();
		int x, c, y;
		vector<pair<int, int> > e;
		for (int i = 0; i < n; ++i) {
			scanf("%d (%d)", &x, &c);
			for (int j = 0; j < c; ++j) {
				scanf("%d", &y);
				if (mp[make_pair(x, y)])
					continue;
				mp[make_pair(x, y)] = mp[make_pair(y, x)] = 1;
				e.push_back(make_pair(min(x , y), max(x , y)));
			}
		}
		memset(par, -1, sizeof par);
		for (int i = 0; i < sz(e); ++i) {
			merge(e[i].fr, e[i].sc);
		}
		set<int> st;
		for (int i = 0; i < n; ++i) {
			st.insert(root(i));
		}
		int mx = sz(st);

		vector<pair<int,  int> > ans;
		for (int i = 0; i < sz(e); ++i) {
			memset(par, -1, sizeof par);
			st.clear();
			for (int j = 0; j < sz(e); ++j) {
				if (j == i)
					continue;
				merge(e[j].fr, e[j].sc);
			}
			for (int j = 0; j < n; ++j) {
				st.insert(root(j));
			}
			if(sz(st) > mx)
				ans.push_back(e[i]);
		}
		printf("%d critical links\n" , sz(ans));
		sort(all(ans));
		for (int i = 0; i < sz(ans); ++i) {
			printf("%d - %d\n",  ans[i].fr , ans[i].sc);
		}
		puts("");
	}
}
