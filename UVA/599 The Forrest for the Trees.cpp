#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

int par[107]; //set to -1
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
int nod[30];
int main() {
	int t;
	cin >> t;
	while(t--)
	{
		memset(par , -1 , sizeof par);
		memset(nod , 0 , sizeof nod);
		string s;
		cin >> s;
		while(s[0]  != '*')
		{
			merge(s[1] - 'A' , s[3] - 'A');
			cin >> s;
		}
		cin >> s;
		for (int i = 0; i < sz(s); i += 2) {
			nod[s[i] - 'A'] = 1;
		}
		set<pair<int , int> > st;
		for (int i = 0; i < 26; ++i) {
			if(nod[i])
				st.insert(make_pair(root(i) , -par[root(i)]));
		}
		int a , b;
		a = b = 0;
		for(auto x:st)
			if(x.sc == 1)b++;
			else a++;

		printf("There are %d tree(s) and %d acorn(s).\n", a , b);
	}

}
