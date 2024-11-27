#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    dp[0][0] = true;
    for (int i = 1; i <= sum; ++i) {
        dp[0][i] = false;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (j - a[i] >= 0) dp[i][j] |= dp[i - 1][j - a[i]];
            dp[i][j] |= dp[i - 1][j];
        }
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= sum; ++i) {
        if (dp[n][i]) ans.push_back(i); 
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }
}
