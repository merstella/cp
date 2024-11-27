// segment tree recursion used for any associative operations: sum, min/max, multiply, modulo mul, matrix, bitwise or and xor 
// gcd (N log^2 N)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e9 + 1;
struct segtree {
	int size;
	vector<ll> mins;
	void init(int n) {
		size = 1;
		while (size < n) size *= 2; // lam cho size tro thanh power cua 2
		mins.resize(2 * size, inf); // gia su nhu cay chua full thi add cac inf o duoi de sl dung bang power of 2
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)a.size()) {
				mins[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) /2; 
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
	}
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			mins[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		} else {
			set(i, v, 2 * x + 2, m, rx);
		}
		mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	ll calc(int a, int b, int x, int lx, int rx) {
		if (lx >= b || rx <= a) return inf;
		if (a <= lx && rx <= b) return mins[x];
		int m = (lx + rx) / 2;
		return min(calc(a, b, 2 * x + 1, lx, m), calc(a, b, 2 * x + 2, m, rx));
	}
	ll calc(int a, int b){
		return calc(a, b, 0, 0, size);
	}
};
int main()  {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	segtree st;
	st.init(n);

	vector<int> a(n);
	for (auto &i : a) cin >> i;
	st.build(a);

	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int k, u;
			cin >> k >> u;
			st.set(k - 1, u);
		} else {
			int a, b;
			cin >> a >> b;
			a--;
			cout << st.calc(a, b) << '\n';
		}
	}
	cout << '\n';
	return 0;
} 
