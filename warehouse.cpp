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
	int n, T, D;
	cin >> n >> T >> D;

	vector<vector<int>> dp(n + 1, vector<int>(T + 1, 0));
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}	
	vector<int> times(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> times[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int t = 0; t <= T; ++t) {
			if (t >= times[i]) {
				for (int d = 1; d <= D; ++d) {
					if (i - d >= 0)
						dp[i][t] = max(dp[i][t], dp[i - d][t - times[i]] + a[i]);
				}
			}
		}
	}
	debug(dp);
	int ans = -inf;
	for (int i = 1; i <= n; ++i) {
		for (int t = 0; t <= T; ++t) {
			ans = max(ans, dp[i][t]);
		}
	}
	cout << ans;
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