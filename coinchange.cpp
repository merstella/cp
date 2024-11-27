#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "D:\cp\debug.h"
#else
#define debug(...) 12
#endif

const int MOD = 1e9+ 7;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x;
	cin >> n >> x;

	vector<int> D(n);

	for (int i =0; i < n; ++i) cin >> D[i];

	vector<int> dp(x + 1);
	dp[0] = 1;
	for (int i = 1; i <= x; ++i) {
		vector<bool> marked(n, false);
		for (int d = 0; d < n; ++d) {
			if (i - D[d] >= 0 && !marked[i - D[d]]) {
				dp[i] += dp[i - D[d]];
				marked[D[d]] = true;
				marked[i - D[d]] = true;
				dp[i] %= MOD;
			}
		}
	}

	
}