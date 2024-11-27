#include <bits/stdc++.h>
using namespace std;

signed main() {
	srand(time(0));
	int n = rand()%102;
	cout << n << ' ' << 3 << '\n';

	string s(n);
	for (int i = 0; i < n; ++i) {
		int ran = rand()%26 + 97;
		s[i] = char(ran);
		cout << s[i];
	}
	cout << '\n';
	cout << random_suffle(s.begin(), s.end());
} 