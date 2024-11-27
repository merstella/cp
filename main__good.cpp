#include<bits/stdc++.h>

#define x first
#define y second
#define C(i) str[0][i]!=str[1][i]
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N =210, Mod = 998244353, P = 2048;

void solve() {
    int n,k;
    cin >>n >>k;
    string s,t;
    cin >>s >>t;
    vector<int> cnt(26,0);
    bool ok=true;
    for(int i=0;i<n;i++){
        if(i>=k||i+k<n){
            cnt[s[i]-'a']++,cnt[t[i]-'a']--;
        }else {
            ok&=(s[i]==t[i]);
        }
    }
    if(ok&&count(cnt.begin(),cnt.end(),0)==26) puts("YES");
    else puts("NO");
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}

