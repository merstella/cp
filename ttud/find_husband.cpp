#include <bits/stdc++.h>
using namespace std;

int a[22];
int x[22];
int best = INT_MAX;
int f = 0;
int cmin = INT_MAX;
int n, m;
void Try(int i) {
	for (int val = 0; val <= 1; ++val) {
		x[i] = val;
		if (val == 1) f += a[i];
		if (i == n - 1) {
			if (m >= f && m - f < best) {
				best = m - f;
			}
		} else {
			if (f < m) Try(i + 1);
		}
		if (val == 1) f -= a[i];
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cin >> m;
	Try(0);
	cout << best;
	return 0;
}

