#include <bits/stdc++.h>
using namespace std;

int main() {
	int seed; cin >> seed;
	srand(seed);
	int n = 4;
	cout << n << ' ' << 3 << '\n';

	string s;
	for (int i = 0; i < n; ++i) {
		int ran = rand()%26 + 97;
		s += char(ran);
		cout << s[i];
	}
	cout << '\n';
	random_shuffle(s.begin(), s.end());
	cout << s;
} 