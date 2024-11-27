#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 12
#endif

const int LOG = 22;

int calc(int l, int r, vector<vector<int>> &rmq) {
    if (l > r) swap(l, r);
    int j = (int)log2(r - l + 1);
    debug(j);
    return max(rmq[l][j], rmq[r - (1 << j) + 1][j]);
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    // cout << log2(5);
    int n;
    cin >> n;

    vector<vector<int>> rmq(n, vector<int>(LOG));
    std::vector<int> a(n);
    for (auto &i : a) cin >> i;

    for (int i = 0; i < n; ++i) {
        rmq[i][0] = a[i];
    }

    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i + (1 << (j - 1)) < n) 
                rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    int m;
    cin >> m;
    int x, y;
    cin >> x >> y;
    long long ans = 0;

    ans += calc(x, y, rmq);
    m--;
    while (m--) {
        if (n == 1) {
            x = 0;
            y = 0;
        } else {
            x = (x + 7) % (n - 1);
            y = (y + 11) % n;
        }
        ans += calc(x, y, rmq);
        debug(x, y, ans);
    }

    cout << ans << '\n';
}
