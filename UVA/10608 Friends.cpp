#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int par[30007];
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n , m;
		scanf("%d %d" , &n , &m);
		memset(par , -1 , sizeof par);
		for (int i = 0; i < m; ++i) {
			int x , y;
			scanf("%d %d" , &x , &y);
			x--;
			y--;
			merge(x , y);
		}
		int mx = 1;
		for (int i = 0; i < n; ++i) {
			int r = root(i);
			mx = max(mx , -par[r]);
		}
		cout << mx << endl;

	}
}
