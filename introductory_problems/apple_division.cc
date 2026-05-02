#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve_h(ll &ans, vt<ll> arr, int idx, ll sum, ll total) {
    if (idx == arr.size()) {
        ans = min(ans, abs(total - sum - sum));
        return;
    }
    solve_h(ans, arr, idx+1, sum, total);
    solve_h(ans, arr, idx+1, sum + arr[idx], total);
}

void solve() {
    int n;
    cin >> n;
    vt<ll> arr(n);
    for (auto &v : arr) {
        cin >> v;
    }

    ll total = 0;
    for (auto v : arr) {
        total += v;
    }

    ll ans = INT_MAX;
    solve_h(ans, arr, 0, 0, total);
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