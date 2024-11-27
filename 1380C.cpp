#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
    #include "debug.h"
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
#define fi      first
#define se      second
#define all(a)  a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
const int maxn = 1e5 + 2;
const int MOD = 1e9 + 7;
const int inf = INT_MAX;
const ll linf = LLONG_MAX;
int num[maxn];
void aine() {
	ll n, x;
	cin >> n >> x;
	vector<ll>a(n);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(rall(a));
	ll cur = 1, ans = 0;
	for (ll i = 0; i < n; ++i) {
		if (1ll * a[i] * cur >= x) {
			cur = 0;
			ans++;
		}
		cur++;
	}
	cout << ans << '\n';
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t; 
    while (t--) { aine(); } cout << '\n';
}