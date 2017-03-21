#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int par[50007];
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
	int ts = 1;
	while (1) {
		if (n + m == 0)
			break;
		memset(par, -1, sizeof par);
		for (int i = 0; i < m; ++i) {
			int x , y;
			scanf("%d %d", &x , &y);
			x--;
			y--;
			merge(x , y);
		}
		set<int> ans;
		for (int i = 0; i < n; ++i) {
			ans.insert(root(i));
		}
		printf("Case %d: " , ts);
		ts++;
		printf("%d\n",sz(ans));
		scanf("%d %d", &n, &m);
	}

}
