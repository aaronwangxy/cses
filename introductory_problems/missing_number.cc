#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    ll n;
    cin >> n;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans ^= i;
    }

    for (int i = 0; i < n - 1; ++i) {
        int v;
        cin >> v;
        ans ^= v;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}