#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (auto& v:a) cin >> v;

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans -= min(0, a[i] - a[i-1]);
        a[i] = max(a[i],a[i-1]);
    }
    cout << ans << "\n";
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