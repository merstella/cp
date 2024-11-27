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

bool cmp(pair<pii, ll>& a, pair<pii, ll>& b) {
	return a.fi < b.fi;
}
void solve() {
	ll n;
	cin >> n;

	vector<pair<pii, ll>> a(n);
	for (ll i = 0; i < n; ++i) {
		ll x, y, c;
		cin >> x >> y>> c;
		a[i] = {{x, y}, c};
	}

	sort(all(a), cmp);
	debug(a);
	vector<ll> dp(n);
	dp[0] = a[0].se;
	for (ll i = 1; i < n; ++i) {
		dp[i] = a[i].se;
		for (ll j = 0; j < i; ++j) {
			if (a[i].fi.se < a[j].fi.se) continue;
			dp[i] = max(dp[i], dp[j] + a[i].se);
		}
	}
	cout << *max_element(all(dp));
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