#include <bits/stdc++.h> 
using namespace std;

#ifdef LOCAL
#include "D:\cp\debug.h"
#else
#define debug(...) 12
#endif

using ll  = long long;
using ld  = long double;
using pii = pair<int, int>;
template<class T> using MaxHeap = priority_queue<T, vector<T>,    less<T>>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename T1> T amax(T &a, T1 b) { if (b > a) a = b; return a; }
template<typename T, typename T1> T amin(T &a, T1 b) { if (b < a) a = b; return a; }

#define fi            first
#define se            second
#define all(a)  	  (a).begin(), (a).end()
#define rall(a)  	  (a).rbegin(), (a).rend()
#define rep(i, n, k)  for (int i = n; i < k; ++i)
#define repd(i, n, k) for (int i = n; i >= k; --i) 

const int maxN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 1e18;

void solve() {
	int n;
	cin >> n;


	vector<string> a(n);
	for (auto &i : a) cin >> i;

	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][0] = (a[0][0] == '*')? 0 : 1;

	for (int j = 1; j < n; ++j) {
		if (a[0][j] == '.') {
			dp[0][j] = dp[0][j - 1];
		}
	}

	for (int i = 1; i < n; ++i) {
		if (a[i][0] == '.') {
			dp[i][0] = dp[i - 1][0];
		}
	}
	const int MOD = 1e9 + 7;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (a[i][j] == '.') {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}			
		}
	}

	cout << dp[n - 1][n - 1];
}
int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
	}
	return 0;
}