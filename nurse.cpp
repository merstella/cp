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
	int n, k1, k2;
	cin >> n >> k1 >> k2;

	vector<vector<int>> dp(n, vector<int>(2, 0));
	dp[0][0] = 1;
	if (1 >= k1) dp[0][1] = 1; else dp[0][1] = 0;
	for (int i = 1; i < n; ++i){
		dp[i][0] = dp[i - 1][1];
		for (int k = k1; k <= k2; ++k) {
			if (i - k >= 0) dp[i][1] += dp[i - k][0];
			else if (i - k == -1) dp[i][1] += 1;
		}
	}
	debug(dp);
	cout << dp[n - 1][0] + dp[n - 1][1];
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