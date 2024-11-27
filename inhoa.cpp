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

bool inside(int i, int j, int& n, int& m) {
	return (0 <= i && i < n) && (0 <= j && j < m);
}
void solve() {
	int n, m;
	cin >> n >> m;

	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	set<pii> pos;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '#') {
				if (inside(i + 1, j, n, m)) pos.insert({i + 1, j});
				if (inside(i + 1, j + 1, n, m)) pos.insert({i + 1, j + 1});
				if (inside(i, j + 1, n, m)) pos.insert({i, j + 1});
			}
		}
	}
	for (auto it = pos.begin(); it != pos.end(); ++it) {
		auto [u, v] = *it;
		a[u][v] = '#';
	}
	for (auto i : a) cout << i << '\n';
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