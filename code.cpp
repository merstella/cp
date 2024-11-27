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
#define all(a)        (a).begin(), (a).end()
#define rall(a)        (a).rbegin(), (a).rend()
#define rep(i, n, k)  for (int i = n; i < k; ++i)
#define repd(i, n, k) for (int i = n; i >= k; --i) 

const int maxN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> falldmg(n);
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            falldmg.push_back(a[i - 1] - a[i]);
        } else falldmg.push_back(0);
    }
    
    vector<int> f(falldmg.size() + 1);
    f[0] = 0;
    for (int i = 1; i < falldmg.size() + 1; ++i) {
        f[i] = f[i - 1] + falldmg[i - 1];
    }
    while (m--) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        cout << f[q] - f[p] << '\n';
    }
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