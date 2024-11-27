#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "D:\cp\debug.h"
#else
#define debug(...) 12
#endif

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	vector<int> b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int j =0; j < m; ++j) {
		cin>> b[j];
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 0; i <= m; ++i) {
		dp[0][i] = 0;
	}
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);	
			if (a[i - 1] == b[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1] + 1;
		}
	}
	cout << dp[n][m];
	// debug(dp);
}