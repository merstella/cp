#include <bits/stdc++.h>
using namespace std;

const int N = 50;
bool col[N], diag1[N], diag2[N];
vector<string> a;
int n;
int ans = 0;
void Try(int r) {
	for (int c = 0; c < n; ++c) {
		if (a[r][c] == '*') {
			continue;
		}
		if (col[c] || diag1[r + c] || diag2[r - c + n - 1]) continue;
		col[c] = diag1[r + c] = diag2[r - c + n - 1] = 1;
		if (r == n - 1) {
			ans++;
		}
		else Try(r + 1);
		col[c] = diag1[r + c] = diag2[r - c + n - 1] = 0;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	string s;
	while (cin >> s) {
		a.push_back(s);
	}

	n = a.size();
	Try(0);
	cout << ans;
	return 0;
}