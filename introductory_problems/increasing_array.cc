#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto &v : arr) {
        cin >> v;
    }
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += max(0, arr[i-1] - arr[i]);
        arr[i] = max(arr[i], arr[i-1]);
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