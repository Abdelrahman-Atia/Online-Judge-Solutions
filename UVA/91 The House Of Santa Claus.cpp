#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int adj[5][5] = { { 0, 1, 1, 0, 1 }, { 1, 0, 1, 0, 1 }, { 1, 1, 0, 1, 1 }, { 0,
		0, 1, 0, 1 }, { 1, 1, 1, 1, 0 } };

void gen(int idx = 0, string ans = "") {
	ans += char('1' + idx);
	if (sz(ans) == 9) {
		cout << ans << endl;
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (adj[idx][i] == 1) {
			adj[idx][i] = adj[i][idx] = 0;
			gen(i, ans);
			adj[idx][i] = adj[i][idx] = 1;
		}
	}
}
int main() {
	gen();
}
