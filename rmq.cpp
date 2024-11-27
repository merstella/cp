#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
    #include "debug.h"
#else
	#define debug(...) 12
#endif
using ll = long long; 
const int MOD = 998244353;
vector<int> phi;
ll power(ll x, unsigned long long y, unsigned long long m) {
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}
ll modInverse(ll b, ll m) {
    int g = gcd(b, m);
    if (g != 1)
        return -1;
    else {
        return power(b, m - 2, m);
    }
}
void phi_1_to_n(int n) {
	phi.resize(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
 	int a, b;
 	cin >> a >> b;
 	phi_1_to_n(max(a, b));
 	ll sum = 0;
 	for (int i = 1; i <= b; ++i) {
 		int d = gcd(a, i);
 		if (d == 1) {
 			sum = (sum % MOD + (phi[a] * phi[i]) % MOD) % MOD;
 		} else {
 			ll inv = modInverse(phi[d], MOD);
 			sum = (sum % MOD + (((phi[a] * phi[i]) % MOD * d % MOD) % MOD * inv) % MOD) % MOD; 
 		}
 	}
 	cout << sum;


}