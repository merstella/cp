#include <bits/stdc++.h>
using namespace std;


int n, K, Q;
int d[15];
int c[15][15];
bool visited[15];

int y[15], x[15];
int f = 0, ans = INT_MAX;
int load[15];
int nbr;
int segment = 0;
int cmin = INT_MAX;
bool checkY(int v, int k) {
	if (v == 0) return true;
	if (visited[v] || load[k] + d[v] > Q) return false;
	return true;
}
bool checkX(int v, int k){
	if (v > 0 && visited[v]) {
		return false;
	} 
	if (load[k] + d[v] > Q) {
		return false;
	}
	return true;
}
void Try_x(int s, int k) {
	if (s == 0) {
		if (k < K) {
			Try_x(y[k + 1], k + 1);
			return;
		}
	}
	for (int v = 0; v <= n; ++v) {
		if (checkX(v, k)) {
			x[s] = v;
			visited[v] = true;
			f += c[s][v];
			load[k] += d[v];
			segment++;
			if (v > 0) {
				if (f + (n + nbr - segment) * cmin < ans) {
					Try_x(v, k);
				}
			} else {
				if (k == K) {
					if (segment == n + nbr) ans = min(ans, f);
				} else {
					if (f + (n + nbr - segment) * cmin < ans) {
						Try_x(y[k + 1], k + 1);
					}
				}
			}
			visited[v] = false;
			f -= c[s][v];
			load[k] -= d[v];
			segment--;
		}
	}
}
void Try_y(int k) {
	int s = 0;
	if (y[k - 1] > 0) {
		s = y[k - 1] + 1;
	}
	for (int v = s; v <= n; ++v) {
		if (checkY(v, k)) {
			y[k] = v;
			if (v > 0) segment++;
			visited[v] = true;
			f += c[0][v]; 
			load[k] += d[v];
			if (k < K) {
				Try_y(k + 1);
			} else {
				nbr = segment;
				Try_x(y[1], 1);
			}
			if (v > 0) segment--;
			visited[v] = false;
			f -= c[0][v]; 
			load[k] -= d[v];
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> K >> Q;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			cin >> c[i][j];
			if (i != j) cmin = min(cmin, c[i][j]);
		}
	}
	y[0] = 0;
	Try_y(1);
	cout << ans << '\n';
	return 0;
}