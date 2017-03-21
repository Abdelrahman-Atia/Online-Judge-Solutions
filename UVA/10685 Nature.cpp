#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int par[5007];
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

	int n, m;
	scanf("%d %d", &n, &m);
	while (1) {
		if (n + m == 0)
			break;
		memset(par, -1, sizeof par);
		map<string, int> idx;
		for (int i = 0; i < n; ++i) {
			string x;
			cin >> x;
			idx[x] = i;
		}
		int mx = 1;
		for (int i = 0; i < m; ++i) {
			string x, y;
			cin >> x >> y;
			merge(idx[x], idx[y]);
			int r = root(idx[x]);
			mx = max(mx, -par[r]);
		}
		cout << mx << endl;
		scanf("%d %d", &n, &m);
	}

}
