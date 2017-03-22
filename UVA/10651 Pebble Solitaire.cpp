#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long
int dp[5000];
bool nomove(bitset<12> mask) {
	for (int i = 2; i < 12; ++i) {
		if ((mask[i - 2] && mask[i - 1] && !mask[i])
				|| (!mask[i - 2] && mask[i - 1] && mask[i]))
			return 0;
	}
	return 1;
}

int solve(bitset<12> mask) {
	if (nomove(mask)) {
		return mask.count();
	}
	int &ret = dp[mask.to_ulong()];
	if (ret + 1)
		return ret;
	ret = 1e9;
	for (int i = 2; i < 12; ++i) {
		if ((mask[i - 2] && mask[i - 1] && !mask[i])
				|| (!mask[i - 2] && mask[i - 1] && mask[i])) {
			bitset<12> nw = mask;

			nw[i - 2].flip();
			nw[i - 1].flip();
			nw[i].flip();
			ret = min(ret, solve(nw));
		}
	}
	return ret;

}

int main() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	while (n--) {
		string x;
		cin >> x;
		bitset<12> mask;
		for (int i = 0; i < 12; ++i) {
			if (x[i] == 'o')
				mask[i] = 1;
		}
		cout << solve(mask) << endl;

	}

}
