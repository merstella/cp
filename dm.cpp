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
template<typename T, typename T1> T chmax(T &a, T1 b) { if (b > a) a = b; return a; }
template<typename T, typename T1> T chmin(T &a, T1 b) { if (b < a) a = b; return a; }
#define fi      first
#define se      second
#define all(a)  a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
const int maxn = 1e5 + 2;
const int MOD = 1e9 + 7;
const int inf = INT_MAX;
const ll linf = LLONG_MAX;

void Shiori() {
    int s = 0;
    string ss = "0100100";
    for (int i = 0; i < ss.size(); ++i) {
        s |= (ss[i] - '0') << i;
    }
    cout << s;
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t; 
    while (t--) { Shiori(); } cout << '\n';
}