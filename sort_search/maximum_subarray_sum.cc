#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto &v : arr) cin >> v;

    ll ans = arr[0];
    ll curr = 0;
    for (auto v : arr) {
        curr += v;
        ans = max(ans, curr);
        curr = max(0LL, curr);
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