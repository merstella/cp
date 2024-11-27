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

void aine() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    multiset<int, greater<int>> s;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        s.insert(it->se);
    }
    while (s.size() > 1) {
        int t = *s.begin();
        int l = *prev(s.end());
        s.erase(s.find(t));
        s.erase(s.find(l));
        s.insert(t - l);
    }
    cout << *s.begin() << '\n';
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t; 
    while (t--) { aine(); } cout << '\n';
}