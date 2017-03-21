#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

const int N = 5e3 + 3;
const int M = 6e4 + 4;

int head[N], work[N], nxt[M], to[M], cap[M], dis[N], que[N];
int edge_cnt, src, snk, back, front, qsz;
//src and snk is different according to the problem

void add_edge(int f, int t, int c) {
	nxt[edge_cnt] = head[f];
	head[f] = edge_cnt;
	to[edge_cnt] = t;
	cap[edge_cnt] = c;
	edge_cnt++;
}

void add_bi_edge(int f, int t, int c) {
	add_edge(f, t, c);
	add_edge(t, f, 0); // 0 if directed edge
}

void init() {
	memset(head, -1, sizeof head);
	edge_cnt = 0;
}

bool bfs() {
	back = front = qsz = 0;
	memset(dis, -1, sizeof dis);
	dis[src] = 0;
	que[qsz++, back++] = src;
	while (qsz) {
		int cur = que[qsz--, front++];
		for (int i = head[cur]; ~i; i = nxt[i]) {
			int t = to[i];
			if (!cap[i] || dis[t] != -1)
				continue;
			dis[t] = dis[cur] + 1;
			if (t == snk)
				return 1;
			que[qsz++, back++] = t;
		}
	}
	return 0;
}

int dfs(int u, int flow = 1e9 + 3) {
	if (!flow)
		return flow;
	if (u == snk)
		return flow;
	for (int &i = work[u]; i != -1; i = nxt[i]) {
		int v = to[i];
		if (!cap[i] || dis[u] + 1 != dis[v])
			continue;
		int f = dfs(v, min(flow, cap[i]));
		if (f) {
			cap[i] -= f;
			cap[i ^ 1] += f;
			return f;
		}
	}
	return 0;
}

long long max_flow() {
	long long ret = 0, flow = 0;
	while (bfs()) {
		memcpy(work, head, sizeof head);
		while ((flow = dfs(src)))
			ret += flow;
	}
	return ret;
}
pair<pair<int, int>, int> in[307];

double Dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow((double) abs(x1 - x2), 2) + pow((double) abs(y1 - y2), 2));
}
int main() {
	int n;
	scanf("%d", &n);
	int ts = 1;
	while (n) {
		init();
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d %d", &in[i].fr.fr, &in[i].fr.sc, &in[i].sc);
		}
		int a, b, R;
		scanf("%d %d %d", &a, &b, &R);
		int x1 = in[a].fr.fr;
		int y1 = in[a].fr.sc;
		int x2 = in[b].fr.fr;
		int y2 = in[b].fr.sc;
		int x, y;
		vector<pair<pair<int, int>, int> > lft, rit;
		for (int i = 1; i <= n; ++i) {
			if (i == a || i == b || in[i].sc == 0)
				continue;
			x = in[i].fr.fr;
			y = in[i].fr.sc;
			int d = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
			if (d < 0)
				lft.push_back(in[i]);
			else
				rit.push_back(in[i]);
		}
		if (sz(lft) > sz(rit))
			swap(lft, rit);
		src = sz(lft) + sz(rit) + 1;
		snk = src + 1;
		for (int i = 1; i <= sz(lft); ++i) {
			add_bi_edge(src, i, 1);
		}
		for (int i = 0; i < sz(lft); ++i) {
			for (int j = 0; j < sz(rit); ++j) {
				int D = ceil(
						Dist(lft[i].fr.fr, lft[i].fr.sc, rit[j].fr.fr,
								rit[j].fr.sc));
				if (D <= R && lft[i].sc > rit[j].sc)
					add_bi_edge(i + 1, (j + 1) + sz(lft), 1);
			}
		}

		for (int i = 1; i <= sz(rit); ++i) {
			add_bi_edge(i + sz(lft), snk, 1);
		}
		printf("Case %d: %lld\n" , ts , max_flow());
		ts++;
		scanf("%d", &n);
	}
}
