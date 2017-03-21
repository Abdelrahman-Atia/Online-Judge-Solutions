#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int in[30];
int used[30];
vector<vector<int> > adj(30);
int main() {
	vector<string> st;
	string x, y;
	cin >> x;
	while (x[0] != '#') {
		st.push_back(x);
		cin >> x;
	}
	for (int i = 1; i < sz(st); ++i) {
		x = st[i - 1];
		y = st[i];
		for (int j = 0; j < min(sz(x), sz(y)); ++j) {
			if (x[j] == y[j])
				continue;
			used[x[j] - 'A'] = used[y[j] - 'A'] = 1;
			in[y[j] - 'A']++;
			adj[x[j] - 'A'].push_back(y[j] - 'A');
			break;
		}
	}
	queue<int> q;
	for (int i = 0; i < 26; ++i) {
		if (!used[i])
			continue;
		if (in[i] == 0)
			q.push(i);
	}
	string ans = "";
	while (!q.empty()) {
		if (sz(q) > 1)
			break;
		int tp = q.front();
		ans += (tp + 'A');
		q.pop();
		for (auto u : adj[tp]) {
			in[u]--;
			if (in[u] == 0)
				q.push(u);
		}
	}
	cout << ans << endl;

}
