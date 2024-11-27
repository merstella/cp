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
int n;
vector<int> mem;
int calc(int n) {
	if (n == 0) return 0;
	if (mem[n] != inf) return mem[n];
	int tmp = n;
	int res = inf;
	while (tmp > 0) {
		int digit = tmp % 10;
		if (digit > 0) {
			res = min(res, calc(n - digit) + 1);
		}
		tmp/=10;
	}
	

	mem[n] = res;
	return res;
}
void solve() {
	cin >> n;	

	mem.resize(n + 1, inf);
	mem[0] = 0;


	cout << calc(n);
	
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