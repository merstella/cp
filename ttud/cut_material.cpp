#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using pii = pair<int, int>;


bool can_cut(int H, int W, vector<pii>& subr) {
	if (subr.empty()) return true;
	int n = subr.size();
	for (int i = 0; i < n; ++i) {
		pii u = subr[i];
		int h = u.fi, w = u.se;
		vector<pii> tmp;
		for (int j = 0; j < n; ++j) {
			if (j == i) continue;
			tmp.push_back(subr[j]);
		}
		if (h <= H && w <= W) {
			return (can_cut(H - h, W, tmp) || can_cut(H, W - w, tmp));
		}
		if (h <= W && w <= H) {
			return (can_cut(H - w, W, tmp) || can_cut(H, W - h, tmp));
		}
	}
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	int n;
	cin >> n;
	vector<pii> subr(n);
	for (int i = 0; i < n; i++) {
		cin >> subr[i].fi >> subr[i].se;
	}
	cout << can_cut(H, W, subr);

	return 0;
}