#include <bits/stdc++.h>
using namespace std;

int n, k;
bool visited[35];
int x[35];
int dist[35][35];
int best = INT_MAX;
int cmin = INT_MAX;
bool canAssign(int val, int load) {
	if (visited[val]) return false;
	if (val > n) {
		if (!visited[val - n]) return false;
	} else if (load + 1 > k) return false;
	return true;
}
int f = 0; int load = 0;
void Try(int i) {
	for (int val = 1; val <= 2 * n; ++val) {
		if (canAssign(val, load)) {
			x[i] = val;
			if (i == 0) f += dist[0][x[i]];
			else f += dist[x[i - 1]][x[i]];
			visited[val] = true;
			if (val <= n) load += 1; else load -=1;
			if (i == 2 * n - 1) {
				if (f + dist[x[i]][0] < best) {
					best = f + dist[x[i]][0];
				}
			} else {
				if (f + cmin * (2 * n - i) < best) {
					Try(i + 1);
				}
			}
			if (i == 0) f -= dist[0][x[i]];
			else f -= dist[x[i - 1]][x[i]];
			visited[val] = false;
			if (val <= n) load -= 1; else load += 1;
		}
	}

}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n >> k;

	for (int i = 0; i <= 2 * n; ++i) {
		for (int j = 0; j <= 2 * n; ++j) {
			cin >> dist[i][j];
			if (i != j) cmin = min(cmin, dist[i][j]);
		}
	}
	Try(0); // 0..2n-1
	cout << best;
	return 0;
}

