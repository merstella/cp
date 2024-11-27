#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int size;
	vector<long long> Maxs;
	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		Maxs.resize(size * 2, 0ll);
	}
	void build(vector<int>& a) {
		build(a, 0, 0, size);
	}
	void build(vector<int>& a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)a.size()) {
				Maxs[x] = a[lx];
			}
			return;
		} 
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		Maxs[x] = max(Maxs[2 * x + 1], Maxs[2 * x + 2]);
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			Maxs[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		} else set(i, v, 2 * x + 2, m, rx);
		Maxs[x] = max(Maxs[2 * x + 1], Maxs[2 * x + 2]);
	}
	long long calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}
	long long calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return Maxs[x];
		int m = (lx + rx) /2;
		long long s1 = calc(l, r, 2 * x + 1, lx, m);
		long long s2 = calc(l, r, 2 * x + 2, m, rx);
		return max(s1, s2);

	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n;

	segtree st;
	st.init(n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	st.build(a);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string op;
		cin >> op;
		if (op == "update") {
			int i, v;
			cin >> i >> v;
			st.set(i - 1, v);
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.calc(l - 1, r) << '\n';
		}
	}
	return 0;
}