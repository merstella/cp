#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 12
#endif
using ll = long long;

const int N = 1024;
const int INF = 1e9;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        bitset<10> tmp;
        cin >> tmp;
        int s = (int)tmp.to_ulong();
        vector<pair<pair<int, int>, int>> pill(m);
        for (int i = 0;i < m; ++i) {
            cin >> pill[i].second;
            cin >> tmp;
            pill[i].first.first = (int) tmp.to_ulong();
            cin >> tmp;
            pill[i].first.second = (int) tmp.to_ulong();
        }
        vector<vector<pair<int, int>>> g(N);
        for (int u = 0; u < N; ++u) {
            for (int i = 0; i < m; ++i) {
                int v = (u & ~pill[i].first.first) | pill[i].first.second;
                int uv = pill[i].second; 
                g[u].push_back({v, uv});
            }
        }
        
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> d(N, INF);
        d[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [du, u] = pq.top(); pq.pop();
            if (du != d[u]) continue;
            for (auto [v, uv] : g[u]) {
                if (d[v] > d[u] + uv) {
                    d[v] = d[u] + uv;
                    pq.push({d[v], v});
                }
            }
        }
        if (d[0] == INF) cout << -1 << '\n'; else cout << d[0] << '\n';
    }
}
