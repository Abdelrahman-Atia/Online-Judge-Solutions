#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int par[100007];
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
		int k;
		scanf("%d" , &k);
		memset(par , -1 , sizeof par);
		map<string , int> idx;
		int mx = 0;
		for (int i = 0; i < k; ++i) {
			string x , y;
			cin >> x >> y;
			if(idx.count(x) == 0)idx[x] = mx++;
			if(idx.count(y) == 0)idx[y] = mx++;
			merge(idx[x] , idx[y]);
			int r = root(idx[x]);
			cout << -par[r] << endl;
		}


	}
}
