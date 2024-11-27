#include <bits/stdc++.h>
using namespace std;

using ll = long long; 
#define all(x) x.begin(), x.end()
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) 
   		cin >> i;
   	//tail[i] = minimum element of lis subsequence with len i
    
    vector<int> tail;
    for (int i = 0; i < n; ++i) {
        auto idx = lower_bound(all(tail), a[i]);
        if (idx == tail.end()) {
            tail.push_back(a[i]);
        }
        else {
            tail[idx - tail.begin()] = a[i];
        }
    }

    cout << tail.size();
}