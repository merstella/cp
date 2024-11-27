#include <bits/stdc++.h>
using namespace std;

#define func(x, y) gcd(x, y)

const int N = 1e6 + 3;
const int K = 19;

int st[K + 1][N];
int a[N];
// int lg[N];
int log2_floor(unsigned long long x) {
	return (x != 0)? 63 - __builtin_clzll(x) : -1;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	// precompute log2 value for all x <= N
	// lg[1] = 0;
	// for (int i = 2; i < N; ++i) {
	// 	lg[i] = lg[i / 2] + 1;
	// }

	for (int j = 0; j < n; ++j) {
		st[0][j] = a[j];
		cout << st[0][j] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= K; ++i) {
		for (int j = 0; j + (1 << i) - 1 < n; ++j) {
			st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			cout << st[i][j] << ' ';
			if (j + (1 << i) - 1 == n - 1) cout << '\n';
		}
	}

	
	
	return 0;	
}